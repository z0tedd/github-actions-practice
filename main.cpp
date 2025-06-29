#include "src/CityInfoController.h"
#include "src/HelloController.h"
#include <cstdio>
#include <drogon/drogon.h>

int main() {
  app().registerHandler(
      "/",
      [](const HttpRequestPtr &request,
         std::function<void(const HttpResponsePtr &)> &&callback) {
        LOG_INFO << "connected:" << (request->connected() ? "true" : "false");
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("Server started");
        callback(resp);
      },
      {Get});

  HelloController hc;
  CityInfoController cic;

  drogon::app().loadConfigFile("config.json");

  drogon::app().run();
  printf("Server started");
}
