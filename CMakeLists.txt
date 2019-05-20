cmake_minimum_required (VERSION 3.0)

project (final_proj)

set(HEADER_FILES HashTable.h)

add_library(HashTable HashTable.cpp ${HEADER_FILES})

add_executable(Dictionary Dictionary.cpp ${HEADER_FILES})

target_link_libraries(Dictionary HashTable)

target_compile_options(Dictionary PRIVATE -std=c++0x -g -Wall)
