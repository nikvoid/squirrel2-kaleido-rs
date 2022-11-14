cmake_minimum_required(VERSION 3.0.0)
project(squirrel VERSION 0.1.0)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_definitions(-DGARBAGE_COLLECTOR -D_CRT_SECURE_NO_WARNINGS)

add_subdirectory(squirrel)
add_subdirectory(sqstdlib)