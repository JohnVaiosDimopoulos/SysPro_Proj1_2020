#include <gtest/gtest.h>
#include "../System_Comands/Disease_Frequency/Disease_Frequency.cpp"
#include "../System_Comands/Global_Disease/Global_Disease.cpp"
#include "../System_Comands/Insert_Patient_Record/Insert_Patient_Record.cpp"
#include "../System_Comands/Num_Current_Patients/Num_Current_Patients.cpp"
#include "../System_Comands/Record_Patient_Exit/Record_Patient_Exit.cpp"
#include "../System_Comands/TopK_Countries/TopK_Countries.cpp"
#include "../System_Comands/Topk_Dieseases/TopK_Diseases.cpp"
#include "../Initializer/Initializer.h"
#include "../Argument_Manager/Argument_Manager.h"

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

class System_Command_Tests:public testing::Test{
 protected:
  Arguments arg;
  Initializer initializer;
  Argument_Manager manager;

};

TEST_F(System_Command_Tests,Disease_Frequency) {

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple, with_country;

  simple.insert_node("/diseaseFrequency");
  simple.insert_node("EVD");
  simple.insert_node("01-01-2000");
  simple.insert_node("20-03-2020");

  with_country.insert_node("/diseaseFrequency");
  with_country.insert_node("EVD");
  with_country.insert_node("01-01-2000");
  with_country.insert_node("20-03-2020");
  with_country.insert_node("China");

  Disease_Frequency Disease_freq;
  Disease_freq.Execute_Command(&data, &simple);
  Disease_freq.Execute_Command(&data, &with_country);
  std::cout<<std::endl;

}

TEST_F(System_Command_Tests,Global_Stats){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple, with_date;

  simple.insert_node("/globalDiseaseStats");

  with_date.insert_node("/globalDiseaseStats");
  with_date.insert_node("01-01-2000");
  with_date.insert_node("20-03-2020");

  Global_Disease globalDisease;
  globalDisease.Execute_Command(&data,&simple);
  std::cout<<std::endl;
  globalDisease.Execute_Command(&data,&with_date);
}

TEST_F(System_Command_Tests,Insert_Patient_Record){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple, with_date;

  simple.insert_node("/insertPatientRecord");
  simple.insert_node("100");
  simple.insert_node("John");
  simple.insert_node("Dim");
  simple.insert_node("EVD");
  simple.insert_node("Greece");
  simple.insert_node("12-04-2019");

  Insert_Patient_Record insertPatientRecord;
  insertPatientRecord.Execute_Command(&data,&simple);

  with_date.insert_node("/insertPatientRecord");
  with_date.insert_node("101");
  with_date.insert_node("John");
  with_date.insert_node("Dim");
  with_date.insert_node("EVD");
  with_date.insert_node("Greece");
  with_date.insert_node("12-04-2019");
  with_date.insert_node("12-04-2020");

  insertPatientRecord.Execute_Command(&data,&with_date);



}

TEST_F(System_Command_Tests,Num_Current_Patients){

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple, with_dis;

  simple.insert_node("/numCurrentPatients");

  with_dis.insert_node("/numCurrentPatients");
  with_dis.insert_node("EVD");

  Num_Current_Patients numCurrentPatients;
  numCurrentPatients.Execute_Command(&data,&simple);
  numCurrentPatients.Execute_Command(&data,&with_dis);
}

TEST_F(System_Command_Tests,Record_Patient_Exit){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple;

  simple.insert_node("/recordPatientExit");
  simple.insert_node("22");
  simple.insert_node("10-8-2018");

  Record_Patient_Exit recordPatientExit;
  recordPatientExit.Execute_Command(&data,&simple);
}

TEST_F(System_Command_Tests,TopK_Diseases){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple,with_date;

  simple.insert_node("/topk-Disease");
  simple.insert_node("3");
  simple.insert_node("China");

  TopK_Diseases topKDiseases;
  topKDiseases.Execute_Command(&data,&simple);

  with_date.insert_node("/topk-Disease");
  with_date.insert_node("4");
  with_date.insert_node("China");
  with_date.insert_node("01-01-2000");
  with_date.insert_node("20-03-2020");

  topKDiseases.Execute_Command(&data,&with_date);

}

TEST_F(System_Command_Tests,TopK_Countries){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc, (char **) arg.argv));
  Generic_List<std::string> simple,with_date;

  simple.insert_node("/topk-Countries");
  simple.insert_node("3");
  simple.insert_node("EVD");

  TopK_Diseases topKDiseases;
  topKDiseases.Execute_Command(&data,&simple);

  with_date.insert_node("/topk-Countries");
  with_date.insert_node("4");
  with_date.insert_node("EVD");
  with_date.insert_node("01-01-2000");
  with_date.insert_node("20-03-2020");

  topKDiseases.Execute_Command(&data,&with_date);
}