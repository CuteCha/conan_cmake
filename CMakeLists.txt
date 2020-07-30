cmake_minimum_required(VERSION 3.16)
project(conan_cmake)

message(STATUS "CMAKE_BINARY_DIR: ---${CMAKE_BINARY_DIR}")
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB H_LIST "${PROJECT_SOURCE_DIR}/include/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs)

add_executable(conan_cmake main.cpp ${H_LIST} ${SRC_LIST})
add_executable(test test.cpp ${H_LIST} ${SRC_LIST})

add_library(test_lib SHARED ${SRC_LIST})

message(STATUS "CONAN_LIBS: ---${CONAN_LIBS}")
target_link_libraries(conan_cmake ${CONAN_LIBS})