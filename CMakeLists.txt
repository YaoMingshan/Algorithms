cmake_minimum_required(VERSION 3.14)
project(Algo VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(leetcode)
include(FetchContent)

set(EXTERNAL_PROJECT_DIR ${CMAKE_SOURCE_DIR}/3rdparty)  # 指定外部项目下载目录
add_subdirectory(${EXTERNAL_PROJECT_DIR}/googletest)
add_executable(hello hello.cpp)
target_link_libraries(hello gtest gtest_main)

add_test(NAME hello_test COMMAND hello)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
