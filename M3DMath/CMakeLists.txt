cmake_minimum_required (VERSION 3.8)

SET(LIB_HEADER_DIR "Headers")

add_executable (Math3D "main.cpp")
target_include_directories(Math3D PUBLIC Headers)
ADD_SUBDIRECTORY("Source")