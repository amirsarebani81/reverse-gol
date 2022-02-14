cmake_minimum_required(VERSION 3.14)
project(reverse_gol)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  gol_test
  ../gol.hpp
  ../gol.cpp
  gol_test.cpp
)
target_link_libraries(
  gol_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(gol_test)