#include <gtest/gtest.h>
#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.cpp"
#include "../Patient_List/Patients_List.cpp"


 class List_Test:public testing::Test{

  protected:
   Patient_Record Patient_1{222,"John","Dim","COVID","Greece",new Date(2020,3,15),new Date(2020,4,12)};
  Patient_Record Patient_2{223,"John2","Dim2","COVID","Greece",new Date(2020,3,15),new Date(2020,4,12)};
  Patient_Record Patient_3{223,"John2","Dim2","COVID","Greece",new Date(2020,3,15),new Date(2020,4,12)};
  Generic_List<Patient_Record> patient_list{};
  Patients_List patient_list2{};
};

TEST_F(List_Test, Insert_Patiens_Generic){
 this->patient_list.insert_node(Patient_1);
 ASSERT_EQ(Patient_1,patient_list[0]);
 this->patient_list.insert_node(Patient_2);
 ASSERT_EQ(Patient_2,patient_list[1]);
 ASSERT_EQ(Patient_1,patient_list[0]);
 this->patient_list.insert_node(Patient_3);
 ASSERT_EQ(Patient_1,patient_list[0]);
 ASSERT_EQ(Patient_2,patient_list[1]);
 ASSERT_EQ(Patient_3,patient_list[2]);
}

TEST_F(List_Test,Insert_Patients_Inerit){
  this->patient_list2.insert_node(Patient_1);
  ASSERT_EQ(Patient_1,patient_list2[0]);
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_1.get_record_id()));
  ASSERT_EQ(false,patient_list2.is_id_in_list(200));

  this->patient_list2.insert_node(Patient_2);
  ASSERT_EQ(Patient_1,patient_list2[0]);
  ASSERT_EQ(Patient_2,patient_list2[1]);
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_1.get_record_id()));
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_2.get_record_id()));

  this->patient_list2.insert_node(Patient_3);
  ASSERT_EQ(Patient_1,patient_list2[0]);
  ASSERT_EQ(Patient_2,patient_list2[1]);
  ASSERT_EQ(Patient_3,patient_list2[2]);
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_1.get_record_id()));
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_2.get_record_id()));
  ASSERT_EQ(true,patient_list2.is_id_in_list(Patient_3.get_record_id()));
}
