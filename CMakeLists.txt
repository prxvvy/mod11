cmake_minimum_required(VERSION 3.21)
project(algorithm C)

set(CMAKE_C_STANDARD 23)

add_executable(algorithm src/main.c src/list.c src/include/list.h src/node.c src/include/node.h src/util.c src/include/util.h src/include/bool.h src/rut.c src/include/rut.h)
