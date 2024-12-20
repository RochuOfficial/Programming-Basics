cmake_minimum_required(VERSION 3.29)

add_executable(task-11-1and2 task-1and2.cpp)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/debug_bin")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/release_bin")
else() # Handle other build types (e.g., RelWithDebInfo, MinSizeRel)
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin") # Default location
endif()

set_target_properties(task-11-1and2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
