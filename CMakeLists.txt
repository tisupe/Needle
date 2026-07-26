cmake_minimum_required(VERSION 4.4)
project(Moss LANGUAGES CXX)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)
add_executable(Moss ${SOURCE_FILES})
