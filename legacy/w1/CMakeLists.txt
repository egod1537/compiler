cmake_minimum_required(VERSION 3.20)

project(w1 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(w1 main.c)
add_executable(grader grader.c)

if(MSVC)
  target_compile_options(w1 PRIVATE /W4)
  target_compile_options(grader PRIVATE /W4)
else()
  target_compile_options(w1 PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(grader PRIVATE -Wall -Wextra -Wpedantic)
endif()
