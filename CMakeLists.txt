cmake_minimum_required(VERSION 3.8)

project(snow)

if(UNIX)
    set(SFML_DIR "usr/lib/cmake/SFML")
endif(UNIX)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
add_executable(snow falling-snow/main.cpp)
target_link_libraries(snow sfml-graphics sfml-window sfml-system)

