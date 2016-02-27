#ifndef STRING_PARSER_H_
#define STRING_PARSER_H_

#include <string>

class StringTransformer {
 public:
  void TransformString(std::string& string);
 private:
  void TransformCharacter(char& c);
};

#endif
