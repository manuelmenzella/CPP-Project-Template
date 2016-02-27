#include "gtest/gtest.h"

#include "string_transformer.h"


struct StringTransformerData {
  std::string input;
  std::string output;
};


struct StringTransformerTest
  : testing::Test,
    testing::WithParamInterface<StringTransformerData> {

  StringTransformer string_transformer;

};


TEST_P(StringTransformerTest, MainTest) {
  auto data = GetParam();

  std::string testing_string = data.input;
  string_transformer.TransformString(testing_string);

  EXPECT_EQ(data.output, testing_string);
}


INSTANTIATE_TEST_CASE_P(Default, StringTransformerTest, testing::Values(
  StringTransformerData{"Hey", "HEY"},
  StringTransformerData{"Hey!", "HEY!"},
  StringTransformerData{"all_lowercase", "ALL_LOWERCASE"},
  StringTransformerData{"with_numbers_98", "WITH_NUMBERS_98"},
  StringTransformerData{"with space", "WITH SPACE"},
  StringTransformerData{"caps SOMEwhere eLSe", "CAPS SOMEWHERE ELSE"},
  StringTransformerData{"symbols.,/?!@#$^&*()_+", "SYMBOLS.,/?!@#$^&*()_+"}
));
