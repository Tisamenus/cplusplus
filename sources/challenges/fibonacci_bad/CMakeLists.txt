cmake_minimum_required(VERSION 3.20)

project(fibonacci_bad LANGUAGES CXX)

add_library(fib fib_bad.cxx fibonacci.h)

target_include_directories(fib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(fibonacci fibonacci.cxx)

target_link_libraries(fibonacci PUBLIC fib)