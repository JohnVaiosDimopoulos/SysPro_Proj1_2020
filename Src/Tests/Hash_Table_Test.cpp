#include <gtest/gtest.h>
#include "../Hash_Table/Hash_Table.cpp"
#include "../Hash_Table/Hash_Bucket_Node.cpp"
#include "../System_Data/System_Data.h"
#include "../Argument_Manager/Argument_Manager.h"
#include "../Initializer/Initializer.h"

class Arguments{
 public:
  int argc = 9;
  const char* argv[9];

  Arguments(){
    argv[0] = "Program_Name";
    argv[1] = "-p";
    argv[2] = "Test_file/records";
    argv[3] = "-h1";
    argv[4] = "15";
    argv[5] = "-h2";
    argv[6] = "15";
    argv[7] = "-b";
    argv[8] = "400";

  }
};


class Hash_Table_Test:public testing::Test{
 protected:
  Arguments arg;
  Initializer initializer;
  Argument_Manager manager;
};

TEST_F(Hash_Table_Test,isert){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
}

TEST_F(Hash_Table_Test,num_curr_patients){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));




  data.get_disease_table()->num_current_patients();
  std::cout<<std::endl;

}

TEST_F(Hash_Table_Test,num_curr_patients_with_disease){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();

  data.get_disease_table()->num_current_patients("EVD");
  data.get_disease_table()->num_current_patients("EVb");
  std::cout<<std::endl;
}

TEST_F(Hash_Table_Test, global_stats) {
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));


  data.get_disease_table()->global_disease_stats();
  std::cout<<std::endl;
}

TEST_F(Hash_Table_Test, global_stats_with_date) {
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_disease_table()->global_disease_stats({2000,1,1},{2020,3,20});
  std::cout<<std::endl;

}

TEST_F(Hash_Table_Test,desiese_freq){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_disease_table()->diseaseFrequency("EVD",{2000,1,1},{2020,20,3});
  std::cout<<std::endl;
}

TEST_F(Hash_Table_Test,desiese_freq_with_country){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_disease_table()->diseaseFrequency("EVD",{2000,1,1},{2020,20,3},"China");
  std::cout<<std::endl;
}

TEST_F(Hash_Table_Test,Topk_disease){
  std::cout<<"topk_diesease"<<std::endl;
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_country_table()->topk_diseases(2,"France");

}

TEST_F(Hash_Table_Test,Topk_disease_with_date){
  std::cout<<"topk_diesease"<<std::endl;
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_country_table()->topk_diseases(2,"France",{2000,01,01},{2020,03,20});

}

TEST_F(Hash_Table_Test,Topk_country){
  std::cout<<"topk_country"<<std::endl;
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_disease_table()->topk_countries(2,"SARSCOV-2");

}

TEST_F(Hash_Table_Test,Topk_country_with_date){
  std::cout<<"topk_country"<<std::endl;
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  data.get_disease_table()->topk_countries(2,"SARSCOV-2",{2000,01,01},{2020,03,20});


}