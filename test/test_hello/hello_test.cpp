// #include <drogon/drogon.h>
// #include <gtest/gtest.h>
// using namespace drogon;
//
// TEST(HelloControllerTest, GetHelloAsync) {
//
//   // std::thread([]() { drogon::app().run(); }).detach();
//   // Use a flag to signal when the test is done
//   bool requestDone = false;
//
//   auto client = HttpClient::newHttpClient("http://127.0.0.1:8848");
//
//   auto req = HttpRequest::newHttpRequest();
//   req->setMethod(Get);
//   req->setPath("/");
//
//   client->sendRequest(req, [&](ReqResult result, const HttpResponsePtr &resp)
//   {
//     EXPECT_EQ(result, ReqResult::Ok);
//     ASSERT_TRUE(resp != nullptr);
//
//     EXPECT_EQ(resp->getStatusCode(), k200OK);
//     EXPECT_EQ(resp->getBody(), "Server started");
//
//     requestDone = true;
//     drogon::app().quit();
//   });
//
//   // while (!requestDone) {
//   //   usleep(1000);
//   // }
//   app().run();
//
//   // Wait until the async request completes (you can add timeout logic if
//   // needed)
// }

#include "../../src/HelloController.cpp" // Assuming this file contains HelloController declaration
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <gtest/gtest.h>

// Test case for HelloController::get
TEST(HelloControllerTest, GetReturnsHelloResponse) {
  // Arrange
  HelloController controller;

  // Create a dummy HttpRequest (not used in this example)
  auto request = drogon::HttpRequest::newHttpRequest();

  // Mock response callback
  drogon::HttpResponsePtr response;
  auto callback = [&response](const drogon::HttpResponsePtr &resp) {
    response = resp;
  };

  // Act
  controller.get(request, std::move(callback));

  // Assert
  ASSERT_NE(response, nullptr);
  EXPECT_EQ(response->getStatusCode(), drogon::k200OK);
  EXPECT_EQ(response->getBody(), "Hello from Drogon!");
}
