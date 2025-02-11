cmake_minimum_required(VERSION 3.30)
project(ECAMemu)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/Inc)
file(GLOB_RECURSE SRC "Src/*.*" "Inc/*.*")

add_executable(ECAMemu main.cpp ${SRC})
