cmake_minimum_required(VERSION 3.26.3)

project(cpp_concurrency_in_action)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(1-1 chapter1/listing1-1.cpp)
add_executable(2-1 chapter2/listing2-1.cpp)
add_executable(2-2 chapter2/listing2-2.cpp)
add_executable(2-3 chapter2/listing2-3.cpp)
add_executable(2-6 chapter2/listing2-6.cpp)
add_executable(2-7 chapter2/listing2-7.cpp)
add_executable(2-8 chapter2/listing2-8.cpp)
add_executable(2-9 chapter2/listing2-9.cpp)
add_executable(3-1 chapter3/listing3-1.cpp)
add_executable(3-8 chapter3/listing3-8.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# add_executable(1-1test chapter1/1-1test.cpp)
# target_link_libraries(1-1test ${GTEST_BOTH_LIBRARIES})