#include "CityInfoController.h"
#include <drogon/HttpResponse.h>

void CityInfoController::getCityInfo(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    const std::string &city) {

  // Dummy data for example purposes
  std::map<std::string, std::string> cityData = {
      {"newyork", "New York is a large city in the United States."},
      {"london", "London is the capital of the United Kingdom."},
      {"tokyo", "Tokyo is the capital of Japan."}};

  std::string cityLower = city;
  std::transform(city.begin(), city.end(), cityLower.begin(), ::tolower);

  auto it = cityData.find(cityLower);
  std::string body;
  if (it != cityData.end()) {
    body = it->second;
  } else {
    body = "City information not found.";
  }

  auto resp = HttpResponse::newHttpResponse();
  resp->setBody(body);
  resp->setStatusCode(k200OK);
  callback(resp);
}
