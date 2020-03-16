#include <gtest/gtest.h>
#include "../Patients_List/Patients_List.cpp"
#include "../Patients_List/Patients_List_Node.cpp"
#include "../Patient_Record/Patient_Record.cpp"


class Patients_List_Test:public testing:: Test{

 protected:
  Patient_Record Patient_1{222,"John","Dim","COVID-19","Greece", new Date(2020,3,19), new Date(2020,4,20)};

  Patient_Record Patient_2{223,"John2","Dim2","H1N1","Greece", new Date(2020,3,19), new Date(2020,4,20)};

  Patient_Record Patient_3{224,"John3","Dim3","FLU-19","Greece", new Date(2020,3,19), new Date(2020,4,20)};
  Patients_List* List;

  virtual void SetUp() {
    List = new Patients_List();
  }

  virtual void TearDown() {
    delete List;
  }

};


TEST_F(Patients_List_Test,Insertion){
  Patients_List_Node* temp = List->insert_node(Patient_1);
  ASSERT_EQ(temp->getPatientRecord(),Patient_1);
  ASSERT_EQ(List->get_head()->getPatientRecord(),Patient_1);
  ASSERT_EQ(List->get_tail()->getPatientRecord(),Patient_1);

  temp = List->insert_node(Patient_2);
  ASSERT_EQ(temp->getPatientRecord(),Patient_2);
  ASSERT_EQ(List->get_head()->getPatientRecord(),Patient_1);
  ASSERT_EQ(List->get_tail()->getPatientRecord(),Patient_2);

  temp = List->insert_node(Patient_3);
  ASSERT_EQ(temp->getPatientRecord(),Patient_3);
  ASSERT_EQ(List->get_head()->getPatientRecord(),Patient_1);
  ASSERT_EQ(List->get_tail()->getPatientRecord(),Patient_3);

}