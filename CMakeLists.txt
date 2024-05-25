cmake_minimum_required(VERSION 3.20)
project(simple_sqlite VERSION 0.1.0 LANGUAGES C CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(simple_sqlite main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
