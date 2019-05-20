cmake_minimum_required (VERSION 3.0)

project (final_proj)

set(HEADER_FILES HashTable.h)

add_library(HashTable HashTable.cpp ${HEADER_FILES})

add_executable(main main.cpp ${HEADER_FILES})

target_link_libraries(main HashTable)

target_compile_options(main PRIVATE -std=c++0x -g -Wall)
