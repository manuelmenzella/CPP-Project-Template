#include "glog/logging.h"

#include "string_transformer.h"


void StringTransformer::TransformString(std::string& string) {
  LOG(INFO) << "Processing string: " << string;

  for (char& character : string) {
    if (isalpha(character)) {
      character = toupper(character);
    }
  }
}

void StringTransformer::TransformCharacter(char& character) {
  character = std::toupper(character);
}
