cmake_minimum_required(VERSION 3.29)

add_executable(task-1-1 task-1.cpp)
add_executable(task-1-2 task-2.cpp)
add_executable(task-1-3 task-3.cpp)
add_executable(task-1-4 task-4.cpp)
add_executable(task-1-5 task-5.cpp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")

set_target_properties(task-1-1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-1-2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-1-3 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-1-4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-1-5 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
