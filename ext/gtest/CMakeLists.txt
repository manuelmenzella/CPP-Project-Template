cmake_minimum_required(VERSION 3.0.0)
project(gtest_builder C CXX)
include(ExternalProject)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    CMAKE_ARGS -DBUILD_GTEST=ON
               -DBUILD_GMOCK=ON  # This also builds GTest
    # Disable install step
    INSTALL_COMMAND ""
)

# Include Dirs
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include PARENT_SCOPE)
set(GMOCK_INCLUDE_DIRS ${source_dir}/googlemock/include PARENT_SCOPE)

# Lib Dirs
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIB_DIRS ${binary_dir}/googlemock/gtest PARENT_SCOPE)
set(GMOCK_LIB_DIRS ${binary_dir}/googlemock/ PARENT_SCOPE)
