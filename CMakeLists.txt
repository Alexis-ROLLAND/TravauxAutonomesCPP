cmake_minimum_required(VERSION 3.10)		# never set less 3.10 min version
project(TestTemplate)

# Build type is debug by default
# call cmake .. -DCMAKE_BUILD_TYPE=Release to change to relase
# call cmake .. -DCMAKE_BUILD_TYPE=Debug to revert to debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 23)  # We're using C++23 standard :)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fanalyzer")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

include_directories(include)

add_executable(testTemplate src/test_Template.cpp src/Template.cpp)





