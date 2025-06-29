cmake_minimum_required(VERSION 3.16)

project(drogon_hello_server VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VCPKG_PATH $ENV{VCPKG_ROOT})
include(${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake)
# Find Drogon package
find_package(Drogon REQUIRED)

# add_executable(hello-server main.cpp src/HelloController.cpp)
add_executable(hello-server main.cpp src/HelloController.cpp src/CityInfoController.cpp)

target_link_libraries(hello-server PRIVATE Drogon::Drogon)

# Install target
install(TARGETS hello-server DESTINATION bin)
