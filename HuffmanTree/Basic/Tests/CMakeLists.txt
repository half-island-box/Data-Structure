cmake_minimum_required(VERSION 3.29)
project(HuffmanTree)

set(CMAKE_CXX_STANDARD 14)
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)

include_directories(.)

add_executable(HuffmanTree ${SRC})
