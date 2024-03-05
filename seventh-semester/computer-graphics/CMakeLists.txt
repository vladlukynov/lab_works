cmake_minimum_required(VERSION 3.26)
project(opengl_labs)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/libs/glut-3.7.6-bin)
link_libraries(${PROJECT_SOURCE_DIR}/libs/glut-3.7.6-bin/glut32.lib)

include_directories(${PROJECT_SOURCE_DIR}/libs/stb)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
