#include <gtest/gtest.h>
#include "../AVL_Tree/AVL_Tree.cpp"
#include "../AVL_Tree/AVL_Tree_Node.cpp"
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
    argv[4] = "200";
    argv[5] = "-h2";
    argv[6] = "300";
    argv[7] = "-b";
    argv[8] = "400";

  }
};

class AVL_Test : public ::testing::Test {
 protected:
  AVL_Tree* Tree;
  Arguments arg;
  Initializer initializer;
  Argument_Manager manager;
  virtual void TearDown() {
    delete Tree;
  }
  virtual void SetUp() {
    Tree = new AVL_Tree();

  }
};

TEST_F(AVL_Test, Test_tree) {

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));

  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();

  while (temp!=NULL){
    Tree->insert(temp);
    Tree->Print();
    std::cout<<std::endl;
    std::cout<<std::endl;
    temp=temp->get_next();
  }

}

TEST_F(AVL_Test,Num_of_current_Pattients_Test) {

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  ASSERT_EQ(0,Tree->num_of_current_Patients());
}

TEST_F(AVL_Test,global_disease_num_test){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }



  ASSERT_EQ(88,Tree->global_disease_num({2000,1,1},{2020,3,20}));
  ASSERT_EQ(0,Tree->global_disease_num({0,0,0},{0,0,0}));
}

TEST_F(AVL_Test,global_disease_num_with_country_test){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  ASSERT_EQ(7,Tree->global_disease_num({2000,1,1},{2020,3,20},"China"));
  ASSERT_EQ(0,Tree->global_disease_num({0,0,0},{0,0,0},"China"));
  ASSERT_EQ(0,Tree->global_disease_num({2000,01,01},{2020,3,20},"EVB"));
}

TEST_F(AVL_Test,topk_disease){
  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  Tree->get_topk_diseases_heap();
}

TEST_F(AVL_Test,topk_disease_with_date){

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  Tree->get_topk_diseases_heap({2000, 01, 01}, {2020, 20, 03});

}

TEST_F(AVL_Test,topk_county){

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  Tree->get_topk_countries_heap();
}

TEST_F(AVL_Test,topk_country_with_date){

  System_Data data = initializer.initalize(manager.manage_arguments(arg.argc,(char**)arg.argv));
  list_node<Patient_Record>* temp = data.get_patient_records_ptr()->get_head();
  while (temp!=NULL){
    Tree->insert(temp);
    temp = temp->get_next();
  }

  Tree->get_topk_countries_heap({2000, 01, 01}, {2020, 03, 20});

}



