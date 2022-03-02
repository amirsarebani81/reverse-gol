cmake_minimum_required(VERSION 3.16)
project(gol_test)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/c9461a9b55ba954df0489bab6420eb297bed846b.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  gol_test
  ../gol.hpp
  ../table.hpp
  gol_test.cpp
)
target_link_libraries(
  gol_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(gol_test)