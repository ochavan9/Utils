cmake_minimum_required (VERSION 3.0.0)
project(DataReader)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

include_directories(include)

file(GLOB_RECURSE SRCS src/*)

add_executable(${PROJECT_NAME} ${SRCS})
