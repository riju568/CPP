#include <drogon/HttpController.h>
#include <drogon/HttpFilter.h>
#include <drogon/drogon.h>
#include <json/json.h>
#include <string>

using namespace drogon;

// ---------------------------------------------------------------------------
// 1. Filter (Middleware): Checks "Authorization: Bearer secret-token"
// ---------------------------------------------------------------------------
class AuthFilter : public HttpFilter<AuthFilter> {
public:
    void doFilter(const HttpRequestPtr& req,
                  FilterCallback&& fcb,
                  FilterChainCallback&& fccb) override {
        std::string authHeader = req->getHeader("Authorization");
        if (authHeader == "Bearer secret-token") {
            fcb();  // Authorized -> continue to route handler
            return;
        }

        Json::Value err;
        err["error"] = "Unauthorized";
        err["hint"] = "Send header 'Authorization: Bearer secret-token'";

        auto resp = HttpResponse::newHttpJsonResponse(err);
        resp->setStatusCode(k401Unauthorized);
        fccb(resp);  // Short-circuit request pipeline
    }
};

// ---------------------------------------------------------------------------
// 2. Controller: Grouped routes under /api/v1/users
// ---------------------------------------------------------------------------
namespace api::v1 {

class Users : public HttpController<Users> {
public:
    METHOD_LIST_BEGIN
    // GET /api/v1/users/{id} protected by AuthFilter
    ADD_METHOD_TO(Users::getUser, "/{id}", Get, "AuthFilter");
    // POST /api/v1/users open endpoint
    ADD_METHOD_TO(Users::createUser, "", Post);
    METHOD_LIST_END

    void getUser(const HttpRequestPtr& req,
                 std::function<void(const HttpResponsePtr&)>&& callback,
                 int id) const {
        Json::Value body;
        body["id"] = id;
        body["username"] = "user_" + std::to_string(id);

        auto resp = HttpResponse::newHttpJsonResponse(body);
        callback(resp);
    }

    void createUser(const HttpRequestPtr& req,
                    std::function<void(const HttpResponsePtr&)>&& callback) const {
        auto jsonPtr = req->getJsonObject();
        if (!jsonPtr || !jsonPtr->isMember("username")) {
            Json::Value err;
            err["error"] = "Missing 'username' field";
            auto resp = HttpResponse::newHttpJsonResponse(err);
            resp->setStatusCode(k400BadRequest);
            callback(resp);
            return;
        }

        Json::Value created;
        created["created"] = true;
        created["username"] = (*jsonPtr)["username"].asString();

        auto resp = HttpResponse::newHttpJsonResponse(created);
        resp->setStatusCode(k201Created);
        callback(resp);
    }
};

}  // namespace api::v1

// ---------------------------------------------------------------------------
// 3. C++20 Coroutine Handler: Async HTTP call with co_await
// ---------------------------------------------------------------------------
Task<HttpResponsePtr> fetchProfileCoro(HttpRequestPtr req, std::string userId) {
    auto client = HttpClient::newHttpClient("https://httpbin.org");
    auto upstreamReq = HttpRequest::newHttpRequest();
    upstreamReq->setMethod(Get);
    upstreamReq->setPath("/get");
    upstreamReq->setParameter("user", userId);

    auto [result, upstreamResp] = co_await client->sendRequestCoro(upstreamReq);

    Json::Value payload;
    payload["user_id"] = userId;
    payload["upstream_status"] = (result == ReqResult::Ok && upstreamResp)
        ? static_cast<int>(upstreamResp->getStatusCode())
        : -1;

    auto resp = HttpResponse::newHttpJsonResponse(payload);
    co_return resp;
}

// ---------------------------------------------------------------------------
// 4. Entry Point
// ---------------------------------------------------------------------------
int main() {
    // Register coroutine route
    app().registerHandler("/api/coro/profile/{user_id}", &fetchProfileCoro, {Get});

    // Controllers and filters declared via macros auto-register on app().run()
    app().setThreadNum(4);
    app().addListener("127.0.0.1", 8080);
    app().run();

    return 0;
}