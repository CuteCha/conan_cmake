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

add_executable(conan_cmake main.cpp)
message(STATUS "CONAN_LIBS: ---${CONAN_LIBS}")
target_link_libraries(conan_cmake ${CONAN_LIBS})