cmake_minimum_required(VERSION 3.14)
project(graph1)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph1
        main.cpp
        graphDataMatrix.h
        graphDataVector.h
        graphAlg.h)