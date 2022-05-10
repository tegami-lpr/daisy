cmake_minimum_required(VERSION 3.12.0)

project (mujs C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB MUJS_SOURCES one.c *.h)

add_library(${PROJECT_NAME} STATIC ${MUJS_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_options(${PROJECT_NAME} PRIVATE -std=c99 -pedantic -Wall -Wextra -Wno-unused-parameter)

