# Protected controller route (fails without token -> 401)
curl -i http://127.0.0.1:8080/api/v1/users/7

# Protected controller route (succeeds with token -> 200)
curl -i http://127.0.0.1:8080/api/v1/users/7 -H "Authorization: Bearer secret-token"

# Create user via POST
curl -i -X POST http://127.0.0.1:8080/api/v1/users \
  -H "Content-Type: application/json" \
  -d '{"username":"grace"}'

# Coroutine endpoint
curl -i http://127.0.0.1:8080/api/coro/profile/grace