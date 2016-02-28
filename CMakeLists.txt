set(BIN_NAME project)

# CC Extension
set(CC_EXT cc)

# Entry Point Directory
set(MAIN_DIR main)

# Include Directory
set(INCLUDE_DIR include)

# Source Directory
set(SRC_DIR src)

# Test Directory
set(TEST_DIR test)

####################
####################

cmake_minimum_required(VERSION 3.0.0)

# C++14, Optimization, and Warnings.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Static Linking Option.
option(link_static "Link statically" NO)
if (link_static)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--whole-archive -lpthread")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-whole-archive")
endif()

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Sources
file(GLOB LIB_SOURCES "src/*.${CC_EXT}")

# Main Library
set(LIB_NAME ${BIN_NAME}_lib)
add_library(${LIB_NAME} ${LIB_SOURCES})

# GFlags
find_package(gflags REQUIRED)
target_link_libraries(${LIB_NAME} gflags)

# GLog
find_package(glog REQUIRED)
target_link_libraries(${LIB_NAME} glog)

# Threads
find_package(Threads REQUIRED)
target_link_libraries(${LIB_NAME} ${CMAKE_THREAD_LIBS_INIT})

# Main Executable
file(GLOB MAIN_SOURCES "${MAIN_DIR}/*.${CC_EXT}")
add_executable(${BIN_NAME} ${MAIN_SOURCES})
target_link_libraries(${BIN_NAME} ${LIB_NAME})

# Tests
option(build_tests "Build tests" OFF)

if (build_tests)
  enable_testing()

  # Test Name
  set(TEST_PROJECT_NAME ${LIB_NAME}_test)

  # Test Sources
  file(GLOB TEST_SOURCES "${TEST_DIR}/*.${CC_EXT}")

  # Test Executable
  add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES})

  # Main Dependency
  target_link_libraries(${TEST_PROJECT_NAME} ${LIB_NAME})

  # GTest / GMock
  add_subdirectory(ext/gtest)
  add_dependencies(${TEST_PROJECT_NAME} googletest)

  # GTest
  include_directories(${GTEST_INCLUDE_DIRS})
  target_link_libraries(${TEST_PROJECT_NAME}
    ${GTEST_LIB_DIRS}/libgtest.a
    ${GTEST_LIB_DIRS}/libgtest_main.a
  )

  # GMock
  include_directories(${GMOCK_INCLUDE_DIRS})
  target_link_libraries(${TEST_PROJECT_NAME}
    ${GMOCK_LIB_DIRS}/libgmock.a
    ${GMOCK_LIB_DIRS}/libgmock_main.a
  )

  add_test(test ${TEST_PROJECT_NAME})

endif()
