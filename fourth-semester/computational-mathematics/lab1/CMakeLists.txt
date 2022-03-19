cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

include_directories(../software)

add_executable(lab1 main.cpp countIntegral.cpp createLagrange.cpp countSpline.cpp functions.hpp
        ../software/QUANC8.CPP ../software/SPLINE.CPP)
