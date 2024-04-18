cmake_minimum_required(VERSION 3.29.2)
project(LaBiblioteka VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src)

add_executable(la-biblioteka main.cpp)
