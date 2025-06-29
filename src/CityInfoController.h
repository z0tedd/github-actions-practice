#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class CityInfoController : public HttpController<CityInfoController> {
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(CityInfoController::getCityInfo, "/api/cityinfo/{city}",
                Get); // {city} is a path parameter
  METHOD_LIST_END

  void getCityInfo(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   const std::string &city);
};
