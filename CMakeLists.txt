set(PROJECT_NAME "WeserGamesEngine")
set(LIB_NAME "WeserGamesEngineLib)
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
set(PROJECT_DLLS_DIR "${CMAKE_SOURCE_DIR}/DLL Files")
set(PROJECT_LIB_DIR "${CMAKE_SOURCE_DIR}/Lib")
set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")


cmake_minimum_required(VERSION 3.0)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.h")

#set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
#file(MAKE_DIRECTORY ${BUILD_DIR})
#set(CMAKE_BINARY_DIR ${BUILD_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})

file(GLOB LIB_FILES "${PROJECT_LIB_DIR}/*.*")
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_FILES})

file(GLOB DLL_FILES "${PROJECT_DLLS_DIR}/*.dll")
target_link_libraries(${PROJECT_NAME} PRIVATE ${DLL_FILES})

include(CMakeFilters.cmake)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${LIB_NAME})