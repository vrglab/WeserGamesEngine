cmake_minimum_required(VERSION 3.0)
project(WeserGamesEngine)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME "WeserGamesEngine")
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
set(PROJECT_DLLS_DIR "${CMAKE_SOURCE_DIR}/DLL Files")
set(PROJECT_LIB_DIR "${CMAKE_SOURCE_DIR}/Lib")
set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")

file(GLOB SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.h")

# Create the DLL library
add_library(${PROJECT_NAME}64 SHARED ${SOURCES})

# Include external dependency header directories
target_include_directories(${PROJECT_NAME}64 PRIVATE ${PROJECT_INCLUDE_DIR})

file(GLOB LIB_FILES "${PROJECT_LIB_DIR}/*.*")
target_link_libraries(${PROJECT_NAME}64 PRIVATE ${LIB_FILES})

# Link against dependent DLLs
file(GLOB DLL_FILES "${PROJECT_DLLS_DIR}/*.dll")
target_link_libraries(${PROJECT_NAME}64 PRIVATE ${DLL_FILES})

# Set the output name of the DLL without the "lib" prefix
set_target_properties(${PROJECT_NAME}64 PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Copy source header files to the "Include" folder in the output
set(INCLUDE_OUTPUT_DIR ${CMAKE_BINARY_DIR}/Debug/Include)
file(MAKE_DIRECTORY ${INCLUDE_OUTPUT_DIR})
add_custom_command(TARGET ${PROJECT_NAME}64
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SRC_DIR} ${INCLUDE_OUTPUT_DIR}
    FILES_MATCHING PATTERN "*.h"
)

# Ensure DLL is built before creating import library
add_dependencies(${PROJECT_NAME}64 ${PROJECT_NAME}64)

# Create the import library (.lib) from already compiled object files
add_library(${PROJECT_NAME}Lib STATIC IMPORTED GLOBAL)
set_target_properties(${PROJECT_NAME}Lib PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/Debug/${PROJECT_NAME}.dll)  # Adjust the path and extension as needed

# Link the import library to the DLL
target_link_libraries(${PROJECT_NAME}64 PRIVATE ${PROJECT_NAME}Lib)

include(CMakeFilters.cmake)
