cmake_minimum_required(VERSION 3.5)

project(drogon_hello_server VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(VCPKG_PATH $ENV{VCPKG_ROOT})
include(${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake)
# Find Drogon package
find_package(Drogon REQUIRED)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  main_test
  test/test_hello/hello_test.cpp
  test/test_cityinfo/getcity_test.cpp
  # src/HelloController.cpp
)

target_link_libraries(
main_test
PRIVATE
gtest_main
Drogon::Drogon
)

include(GoogleTest)
gtest_discover_tests(main_test)
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

# Enable coverage report
if(ENABLE_COVERAGE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif()
# add_executable(hello-server main.cpp src/HelloController.cpp)
add_executable(
  hello-server
  main.cpp
  src/HelloController.cpp src/CityInfoController.cpp
)

target_link_libraries(hello-server PRIVATE Drogon::Drogon)

# Install target
install(TARGETS hello-server DESTINATION bin)
