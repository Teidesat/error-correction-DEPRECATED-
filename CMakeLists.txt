cmake_minimum_required(VERSION 3.17)
project(tsat_tc)

set(CMAKE_CXX_STANDARD 17)

add_library(tsat_tc src/encoder/RSC.cpp src/encoder/RSC.h src/other/common.h src/other/common.cpp src/other/CMatrix.cpp src/other/CMatrix.h src/encoder/Viterbi.cpp src/encoder/Viterbi.h src/encoder/Transition.cpp src/encoder/Transition.h)
add_subdirectory(tests)