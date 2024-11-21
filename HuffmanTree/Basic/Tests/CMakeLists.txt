cmake_minimum_required(VERSION 3.29)
project(HuffmanTree)
set(CMAKE_WIN32_EXECUTABLE OFF)  # 确保这是一个控制台程序
set(CMAKE_CXX_STANDARD 14)
aux_source_directory(${PROJECT_SOURCE_DIR} SRC1)

include_directories(.)

add_executable(HuffmanTree hfm_tree.cpp HuffmanTree.cpp HuffmanTree.h)
