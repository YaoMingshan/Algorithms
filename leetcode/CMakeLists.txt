# 收集所有测试文件
file(GLOB TEST_FILES "*.cpp")

# 遍历每个测试文件生成对应的测试目标
foreach(TEST_FILE ${TEST_FILES})
    # 获取测试文件的文件名（不包含扩展名）
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # 添加测试目标
    add_executable(${TEST_NAME} ${TEST_FILE})

    # 链接测试目标与源代码库
    target_link_libraries(${TEST_NAME} PRIVATE algo_lib gtest gtest_main)

    # 设置 include 目录
    # target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()