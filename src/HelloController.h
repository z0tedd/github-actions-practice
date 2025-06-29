#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class HelloController : public HttpController<HelloController> {
public:
  METHOD_LIST_BEGIN
  METHOD_ADD(HelloController::get, "/", Get);
  METHOD_LIST_END

  void get(const HttpRequestPtr &,
           std::function<void(const HttpResponsePtr &)> &&callback);
};
