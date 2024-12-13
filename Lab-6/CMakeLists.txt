cmake_minimum_required(VERSION 3.29)

add_executable(task-6 task.cpp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")

set_target_properties(task-6 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
