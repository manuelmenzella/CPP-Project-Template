#include "glog/logging.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"


int main(int argc, char *argv[]) {
  // Initialize GLog, GFlags, GMock, and GTest.
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  testing::InitGoogleMock(&argc, argv);
  testing::InitGoogleTest(&argc, argv);

  // Run all tests.
  return RUN_ALL_TESTS();
}
