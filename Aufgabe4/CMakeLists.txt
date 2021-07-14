cmake_minimum_required(VERSION 3.19)
project(Aufgabe4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Aufgabe4_new
        ast.cpp
        ast.h
        parser.cpp
        parser.h
        testParser.cpp
        tokenizer.cpp
        tokenizer.h
        utility.h
        vm.h
        vm.cpp
        testVM.cpp)
