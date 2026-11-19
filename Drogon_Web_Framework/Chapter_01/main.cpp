#include <drogon/drogon.h>
#include <functional>

using namespace drogon;

int main() {
    // Register a GET handler at "/"
    app().registerHandler(
        "/",
        [](const HttpRequestPtr& req,
           std::function<void(const HttpResponsePtr&)>&& callback) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k200OK);
            resp->setContentTypeCode(CT_TEXT_PLAIN);
            resp->setBody("Welcome to Drogon - Chapter 1!");
            callback(resp);
        },
        {Get});

    // Configure worker threads (0 = match CPU cores) and start server
    app().setThreadNum(4);
    app().addListener("127.0.0.1", 8080);
    app().run();

    return 0;
}