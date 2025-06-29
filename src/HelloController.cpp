#include "HelloController.h"
#include <drogon/HttpResponse.h>

void HelloController::get(
    const drogon::HttpRequestPtr &,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  auto resp = drogon::HttpResponse::newHttpResponse();
  resp->setBody("Hello from Drogon!");
  resp->setStatusCode(k200OK);
  callback(resp);
}
