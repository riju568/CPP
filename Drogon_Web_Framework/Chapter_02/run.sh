curl http://127.0.0.1:8080/
curl http://127.0.0.1:8080/users/42/posts/hello-drogon
curl "http://127.0.0.1:8080/search?q=drogon&limit=5"
curl http://127.0.0.1:8080/api/status
curl -X POST http://127.0.0.1:8080/api/echo -H "Content-Type: application/json" -d '{"name":"Alice","role":"dev"}'