# 添加源文件
file(GLOB_RECURSE SRC_FILES "*.cpp" "*.h")
foreach(FILE ${SRC_FILES})
    message(STATUS "Found file: ${FILE}")
endforeach()

# 添加库
add_library(algo_lib ${SRC_FILES})
set_target_properties(algo_lib PROPERTIES LINKER_LANGUAGE CXX)

# 设置 include 目录
target_include_directories(algo_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})