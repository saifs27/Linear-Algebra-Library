cmake_minimum_required(VERSION 3.22.1)

project(linalg)

if (MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-W -Wall -Werror)
endif()

add_library(linalg src/matrix.cpp src/sparse.cpp)

target_include_directories(linalg PUBLIC include)
target_include_directories(linalg PRIVATE src)

