#include <gtest/gtest.h>
#include "../Argument_Manager/Argument_Manager.cpp"
#include "../Argument_Data/Argument_Data.cpp"


class Arguments_Correct{
 public:
  int argc = 9;
  const char* argv[9];

  Arguments_Correct(){
    argv[0] = "Program_Name";
    argv[1] = "-p";
    argv[2] = "recordFile";
    argv[3] = "-h1";
    argv[4] = "200";
    argv[5] = "-h2";
    argv[6] = "300";
    argv[7] = "-b";
    argv[8] = "40";

  }
};

class Arguments_Wrong_Num{
 public:
  int argc = 2;
  const char* argv[2];

  Arguments_Wrong_Num(){
    argv[0] = "Program_Name";
    argv[1] = "-p";
  }
};

class Arguments_Wrong_Format{
 public:
  int argc = 9;
  const char* argv[9];

  Arguments_Wrong_Format(){
    argv[0] = "Program_Name";
    argv[1] = "-p";
    argv[2] = "recordFile";
    argv[3] = "-h4";
    argv[4] = "200";
    argv[5] = "-h2";
    argv[6] = "300";
    argv[7] = "-b";
    argv[8] = "40";

  }
};

 class Argument_Manager_Test:public testing:: Test{

  protected:

   Arguments_Correct* arg_correct;
   Arguments_Wrong_Num* arg_wrong_num;
   Arguments_Wrong_Format* arg_wrong_format;

   virtual void TearDown() {
     delete arg_correct;
     delete arg_wrong_num;
     delete arg_wrong_format;
   }

   virtual void SetUp() {
     arg_correct = new Arguments_Correct();
     arg_wrong_num = new Arguments_Wrong_Num();
     arg_wrong_format = new Arguments_Wrong_Format();
   }

 };

TEST_F(Argument_Manager_Test,Correct_Input){
  Argument_Manager manager;
  Argument_Data data = manager.manage_arguments(arg_correct->argc,(char**)arg_correct->argv);
  ASSERT_EQ(data.get_file_name(),"recordFile");
  ASSERT_EQ(data.get_disease_entries(),200);
  ASSERT_EQ(data.get_country_entries(),300);
  ASSERT_EQ(data.get_bucket_size(),40);
}

TEST_F(Argument_Manager_Test,Wrong_Num){
  Argument_Manager manager;
  EXPECT_EXIT(manager.manage_arguments(arg_wrong_num->argc,(char**)arg_wrong_num->argv),::testing::ExitedWithCode(255),"");
}

TEST_F(Argument_Manager_Test,Wrong_Format){
  Argument_Manager manager;
  EXPECT_EXIT(manager.manage_arguments(arg_wrong_format->argc,(char**)arg_wrong_format->argv),::testing::ExitedWithCode(255),"");
}
