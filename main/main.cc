#include <iostream>

#include "glog/logging.h"

#include "string_transformer.h"


int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  LOG(INFO) << "About to start!";

  std::string string = "Hey!";

  StringTransformer string_transformer;
  string_transformer.TransformString(string);

  std::cout << string << std::endl;

  LOG(INFO) << "Done.";
}
