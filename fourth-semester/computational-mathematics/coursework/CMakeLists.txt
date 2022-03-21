cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

include_directories(../RCS)

add_executable(coursework main.cpp functions.hpp calculateIntegral.cpp calculateEquation.cpp calculateT.cpp
        ../RCS/quanc8.cpp ../RCS/zeroin.cpp ../RCS/decomp.cpp)
