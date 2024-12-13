cmake_minimum_required(VERSION 3.29)

add_executable(task-9-2 task-2.cpp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")

set_target_properties(task-9-2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
