cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
project(conan_cmake)

message(STATUS "CMAKE_BINARY_DIR: ---${CMAKE_BINARY_DIR}")
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 11)

# -----------cmake proto--------------------
find_package(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

add_subdirectory(proto)

# 这一句的意义在于可以找到proto新建出来的c++代码
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_executable(write_data test_src/writter.cpp)
TARGET_LINK_LIBRARIES(write_data proto ${PROTOBUF_LIBRARIES})

add_executable(read_data test_src/reader.cpp)
TARGET_LINK_LIBRARIES(read_data proto ${PROTOBUF_LIBRARIES})

add_executable(pb_json test_src/pb_json.cpp)
TARGET_LINK_LIBRARIES(pb_json proto ${PROTOBUF_LIBRARIES})
# -----------cmake proto--------------------

file(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB H_LIST "${PROJECT_SOURCE_DIR}/include/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs)

add_executable(conan_cmake main.cpp ${H_LIST} ${SRC_LIST})

add_executable(test test_src/test.cpp ${H_LIST} ${SRC_LIST})

# -----------cmake yaml cpp--------------------
add_executable(yaml_test test_src/yaml_test.cpp ${H_LIST} ${SRC_LIST})
target_link_libraries(yaml_test PRIVATE yaml-cpp)
set_property(TARGET yaml_test PROPERTY OUTPUT_NAME yaml_test_y)
set_target_properties(yaml_test
        PROPERTIES
        CXX_STANDARD_REQUIRED ON
        OUTPUT_NAME yaml_test_y)
# -----------cmake yaml cpp--------------------

add_executable(smart_ptr test_src/smart_ptr.cpp ${H_LIST} ${SRC_LIST})
add_executable(multi_thread test_src/multi_thread.cpp ${H_LIST} ${SRC_LIST})

add_library(test_lib SHARED ${SRC_LIST})

message(STATUS "CONAN_LIBS: ---${CONAN_LIBS}")
target_link_libraries(conan_cmake ${CONAN_LIBS})