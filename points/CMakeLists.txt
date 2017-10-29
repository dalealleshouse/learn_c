cmake_minimum_required(VERSION 3.5)
project(points)

file(GLOB SOURCES "*.c")
add_executable(points ${SOURCES})

target_link_libraries(points m)
