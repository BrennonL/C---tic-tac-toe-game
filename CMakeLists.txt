cmake_minimum_required(VERSION 3.10)
project(tictactoe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    tictactoe
    main.cpp
    src/board.cpp
)

target_include_directories(
    tictactoe
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)