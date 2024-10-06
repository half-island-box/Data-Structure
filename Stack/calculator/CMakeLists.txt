cmake_minimum_required(VERSION 3.29)
project(calculator)
include_directories(.)
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)

add_executable(calculator ${SRC})
