cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.10)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.13) # tests
endif()

project(TEST VERSION 1.0
	     DESCRIPTION "A TEST"
	     LANGUAGES CXX)

add_executable(test main.cxx useless.h)