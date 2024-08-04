cmake_minimum_required(VERSION 3.28)
project(typeTest)

set(CMAKE_CXX_STANDARD 23)

add_executable(typeTest main.cpp
        Field.h
        Messages/ExampleMessage.h
        Message.h)
