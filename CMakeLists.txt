cmake_minimum_required(VERSION 3.1)

project(snow)

set(SFML_DIR "/usr/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES FALSE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(snow src/main.cpp)
target_link_libraries(snow sfml-graphics)
