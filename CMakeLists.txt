cmake_minimum_required(VERSION 3.15)
project(error-correction)

set(CMAKE_CXX_STANDARD 17)

# Version number
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

configure_file(config/Config.h.in config/Config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/config)
include_directories(include src)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
