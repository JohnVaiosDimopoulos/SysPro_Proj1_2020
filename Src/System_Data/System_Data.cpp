#include "System_Data.h"
#include "../Argument_Data/Argument_Data.h"

//==CONSTRUCTOR-DESTRUCTOR==//
System_Data::System_Data(const Argument_Data &arg_data)
    : disease_table(arg_data.get_disease_entries(),arg_data.get_bucket_size()),
      country_table(arg_data.get_country_entries(),arg_data.get_bucket_size()) {}

Hash_Table* System_Data::get_disease_table(){
  return &disease_table;
}
Hash_Table* System_Data::get_country_table(){
  return &country_table;
}
Patients_List* System_Data::get_patient_records_ptr(){
  return &patient_records;
}

Patients_List System_Data::get_patient_records() const {
  return patient_records;
}
