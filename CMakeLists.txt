cmake_minimum_required(VERSION 3.8)

PROJECT(M3DMath)

SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx" )

ADD_SUBDIRECTORY("M3DMath")