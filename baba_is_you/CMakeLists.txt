cmake_minimum_required(VERSION 3.5)

project(baba_is_you LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-std=c++20 -pedantic-errors -Wall -Wuninitialized")

add_subdirectory(src)
add_subdirectory(tests)
