#include <gtest/gtest.h>
#include "../Tokenizer/Tokenizer.cpp"



 class Tokenizer_Test:public testing::Test{

  protected:
  std::string record = "0 John Jacobs EVD Switzerland 25-09-2002 02-02-2006";


 };

TEST_F(Tokenizer_Test, tokenize_record_test) {
  Tokenizer tokenizer;
  std::string* record_res = tokenizer.tokenize_record(record);
  ASSERT_STREQ("0",record_res[0].c_str());
  ASSERT_STREQ("John",record_res[1].c_str());
  ASSERT_STREQ("Jacobs",record_res[2].c_str());
  ASSERT_STREQ("EVD",record_res[3].c_str());
  ASSERT_STREQ("Switzerland",record_res[4].c_str());
  ASSERT_STREQ("25-09-2002",record_res[5].c_str());
  ASSERT_STREQ("02-02-2006",record_res[6].c_str());
}

TEST_F(Tokenizer_Test,str_to_Date_test){
  Tokenizer tokenizer;
  std::string* record_res = tokenizer.tokenize_record(record);
  Date date_ex_1{2002,9,25};
  Date date_ex_2{2006,2,2};
  ASSERT_EQ(true,tokenizer.str_to_Date(record_res[5])== date_ex_1);
  ASSERT_EQ(true,tokenizer.str_to_Date(record_res[6])==date_ex_2);
}

TEST_F(Tokenizer_Test,tokenize_command){
  Tokenizer tokenizer;
  std::string command = "/command par1 par2";
  Generic_List<std::string> command_list = tokenizer.tokenize_command(command);
  ASSERT_STREQ("/command",command_list[0].c_str());
  ASSERT_STREQ("par1",command_list[1].c_str());
  ASSERT_STREQ("par2",command_list[2].c_str());
}