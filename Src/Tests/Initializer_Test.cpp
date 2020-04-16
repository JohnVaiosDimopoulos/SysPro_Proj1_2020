#include <gtest/gtest.h>
#include "../Initializer/Initializer.cpp"
#include "../Argument_Manager/Argument_Manager.h"
#include "../System_Data/System_Data.cpp"




class Arguments{
 public:
  int argc = 9;
  const char* argv[9];

  Arguments(){
    argv[0] = "Program_Name";
    argv[1] = "-p";
    argv[2] = "Test_file/records";
    argv[3] = "-h1";
    argv[4] = "200";
    argv[5] = "-h2";
    argv[6] = "300";
    argv[7] = "-b";
    argv[8] = "400";

  }
};

class Initializer_Test:public testing::Test{
 protected:
  virtual void SetUp() {
    Arguments arg;
    arg_data = manager.manage_arguments(arg.argc, (char **)arg.argv);
  }

  Initializer initializer;
  Argument_Manager manager;
  Argument_Data arg_data;
};

TEST_F(Initializer_Test,inisialize_test){
  System_Data sys_data = initializer.initalize(arg_data);

  for(int i =0; i< sys_data.get_patient_records_ptr()->get_num_of_nodes(); i++){
    std::cout<<"NUM: "<<i<<" "<<sys_data.get_patient_records_ptr()[0][i]<<std::endl;

  }
}



