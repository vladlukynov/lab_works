cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

include_directories(../software)

add_executable(lab3 main.cpp useRKF.cpp functions.hpp useRungeKuttaMethod.cpp ../software/RKF45.CPP function.cpp)
