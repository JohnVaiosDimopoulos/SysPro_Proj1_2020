#ifndef PROJ_1_SYSTEM_DATA_H
#define PROJ_1_SYSTEM_DATA_H

#include "../Hash_Table/Hash_Bucket_Node.h"
#include "../Hash_Table/Hash_Table.h"
#include "../Argument_Data/Argument_Data.h"
#include "../Patient_List/Patients_List.h"
class System_Data {

 private:
  Hash_Table disease_table;
  Hash_Table country_table;
  Patients_List patient_records;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  System_Data(const Argument_Data &arg_data);


  //==GETTERS==//
  Hash_Table get_disease_table() const;
  Hash_Table get_country_table() const;
  Patients_List get_patient_records() const;
};

#endif //PROJ_1_SYSTEM_DATA_H
