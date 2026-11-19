#include <drogon/drogon.h>
#include <functional>
#include <string>

using namespace drogon;

int main() {
    // 1. Basic GET route (Chapter 1)
    app().registerHandler(
        "/",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k200OK);
            resp->setContentTypeCode(CT_TEXT_PLAIN);
            resp->setBody("Welcome to Drogon! Try /users/42/posts/hello, /search?q=drogon&limit=5, /api/status, or POST /api/echo");
            callback(resp);
        },
        {Get});

    // 2. URL path parameters (Chapter 2)
    app().registerHandler(
        "/users/{user_id}/posts/{slug}",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback,
           int user_id,
           const std::string& slug) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("User #" + std::to_string(user_id) + " | Post: " + slug);
            callback(resp);
        },
        {Get});

    // 3. Query string parameters (Chapter 2)
    app().registerHandler(
        "/search",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback) {
            std::string query = req->getParameter("q");
            std::string limit_str = req->getParameter("limit");

            int limit = 10;
            if (!limit_str.empty()) {
                try {
                    limit = std::stoi(limit_str);
                } catch (...) {
                    auto err = HttpResponse::newHttpResponse();
                    err->setStatusCode(k400BadRequest);
                    err->setBody("Invalid 'limit' query parameter");
                    callback(err);
                    return;
                }
            }

            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("Searching for '" + query + "' (limit=" + std::to_string(limit) + ")");
            callback(resp);
        },
        {Get});

    // 4. Returning a JSON response (Chapter 2)
    app().registerHandler(
        "/api/status",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback) {
            Json::Value body;
            body["status"] = "ok";
            body["framework"] = "Drogon";
            body["version"] = 2;
            body["features"].append("routing");
            body["features"].append("json");

            auto resp = HttpResponse::newHttpJsonResponse(body);
            resp->setStatusCode(k200OK);
            callback(resp);
        },
        {Get});

    // 5. Parsing an incoming JSON POST body (Chapter 2)
    app().registerHandler(
        "/api/echo",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback) {
            auto json_ptr = req->getJsonObject();
            if (!json_ptr) {
                Json::Value err_body;
                err_body["error"] = "Expected valid JSON body";
                auto err_resp = HttpResponse::newHttpJsonResponse(err_body);
                err_resp->setStatusCode(k400BadRequest);
                callback(err_resp);
                return;
            }

            const auto& incoming = *json_ptr;
            std::string name = incoming.get("name", "anonymous").asString();

            Json::Value out;
            out["received_name"] = name;
            out["raw_keys"] = incoming.getMemberNames().size();

            auto resp = HttpResponse::newHttpJsonResponse(out);
            resp->setStatusCode(k201Created);
            callback(resp);
        },
        {Post});

    // Start server on port 8080 with 4 worker threads
    app().setThreadNum(4);
    app().addListener("127.0.0.1", 8080);
    app().run();

    return 0;
}