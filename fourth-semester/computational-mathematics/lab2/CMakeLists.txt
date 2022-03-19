cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

include_directories(../software)

add_executable(lab2 main.cpp countInverseMatrix.cpp multiplyMatrices.cpp subtractMatrices.cpp
        calculateMatrixNorm.cpp initEMatrix.cpp functions.hpp
        ../software/DECOMP.CPP)
