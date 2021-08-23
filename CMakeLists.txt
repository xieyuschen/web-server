cmake_minimum_required(VERSION 3.19)
project(web_server)

set(CMAKE_CXX_STANDARD 11)

add_executable(web_server main.cpp Server.cpp Server.h Log.h)
