cmake_minimum_required(VERSION 3.13)
project(error-correction)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Version number
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

configure_file(config/Config.h.in config/Config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/config)
include_directories(include src)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
