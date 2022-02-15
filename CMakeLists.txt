cmake_minimum_required(VERSION 3.20)
project(rut_lib C)

set(CMAKE_C_STANDARD 23)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(rut_lib ${SRC_FILES})

include_directories(/usr/include/node/ ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/node-addon-api/)
