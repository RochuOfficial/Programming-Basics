cmake_minimum_required(VERSION 3.29)

add_executable(task-4-1 task-1.cpp)
add_executable(task-4-2 task-2.cpp)
add_executable(task-4-3 task-3.cpp)
add_executable(task-4-4 task-4.cpp)
add_executable(task-4-5 task-5.cpp)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/debug_bin")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/release_bin")
else() # Handle other build types (e.g., RelWithDebInfo, MinSizeRel)
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin") # Default location
endif()

set_target_properties(task-4-1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-4-2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-4-3 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-4-4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
set_target_properties(task-4-5 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
