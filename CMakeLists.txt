set(PROJECT_NAME "WeserGamesEngine")
set(LIB_NAME "WeserGamesEngine")
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")


cmake_minimum_required(VERSION 3.0)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.h")

#set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
#file(MAKE_DIRECTORY ${BUILD_DIR})
#set(CMAKE_BINARY_DIR ${BUILD_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${LIB_NAME})