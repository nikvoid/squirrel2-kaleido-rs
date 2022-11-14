cmake_minimum_required(VERSION 3.0.0)
project(squirrel VERSION 2.2.4)

include(CTest)
enable_testing()

add_library(squirrel STATIC
    sqapi.cpp
    sqbaselib.cpp
    sqfuncstate.cpp
    sqdebug.cpp
    sqlexer.cpp
    sqobject.cpp
    sqcompiler.cpp
    sqstate.cpp
    sqtable.cpp
    sqmem.cpp
    sqvm.cpp
    sqclass.cpp
)

add_compile_options(-O2 -Wall)

target_include_directories(squirrel PRIVATE ../include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
