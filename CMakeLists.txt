cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cpp_chess VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES src/*.cpp)

include_directories(include)

add_library(cpp_chess SHARED
    ${SOURCES}
)