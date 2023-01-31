cmake_minimum_required(VERSION 3.14)
project(disjoint_set_tc)
find_package(GTest CONFIG REQUIRED) 
add_executable(
  disjoint_set_tc
  disjoint_set_test.cpp
  ../GraphValidTree/validtree.cpp
)
target_link_libraries(
  disjoint_set_tc 
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(disjoint_set_tc)
