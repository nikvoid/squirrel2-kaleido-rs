cmake_minimum_required(VERSION 3.0.0)
project(sqstdlib VERSION 2.2.4)

add_library(sqstdlib STATIC
    sqstdblob.cpp
    sqstdio.cpp
    sqstdstream.cpp
    sqstdmath.cpp
    sqstdsystem.cpp
    sqstdstring.cpp
    sqstdaux.cpp
    sqstdrex.cpp
)

add_compile_options(-O2  -fno-rtti -Wall)

target_include_directories(sqstdlib PRIVATE ../include)