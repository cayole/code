cmake_minimum_required(VERSION 3.20.0)
project(test)
aux_source_directory(src SRC)
include_directories(inc)
add_executable(test ${SRC})
