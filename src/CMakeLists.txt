project(MyHello CXX)
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE TYPES_SOURCES "*.cpp")
file(GLOB_RECURSE TYPES_HEADERS "*.h")

set (TYPES_INCLUDE_DIRS "")
foreach (_headerFile ${TYPES_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND TYPES_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES TYPES_INCLUDE_DIRS)

add_library(types ${TYPES_SOURCES})
target_include_directories(types PRIVATE ${TYPES_INCLUDE_DIRS})
