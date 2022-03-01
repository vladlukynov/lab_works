cmake_minimum_required(VERSION 3.21)
project(computational-mathematics)

set(CMAKE_CXX_STANDARD 14)

include_directories(software)

# lab1
# add_executable(computational-mathematics lab1/main.cpp lab1/countIntegral.cpp lab1/createLagrange.cpp lab1/countSpline.cpp software/QUANC8.CPP software/SPLINE.CPP)

# lab2
 add_executable(computational-mathematics lab2/main.cpp lab2/countInverseMatrix.cpp lab2/multiplyMatrices.cpp lab2/subtractMatrices.cpp lab2/calculateMatrixNorm.cpp lab2/initEMatrix.cpp software/DECOMP.CPP)

# lab3
# add_executable(math_labs lab3/lab3.cpp)
