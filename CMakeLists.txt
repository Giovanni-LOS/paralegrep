cmake_minimum_required(VERSION 3.10)
project(paralegrep)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(paralegrep 
    src/main.c 
    src/thread_dispatcher.c 
    src/utils.c
)
