#include "Num_Current_Patients.h"

bool Num_Current_Patients::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(tokenized_command->get_num_of_nodes()!=1 && tokenized_command->get_num_of_nodes()!=2){
    std::cout<<"Invalid parameters"<<std::endl;
    return false;
  }
}

void Num_Current_Patients::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(!validate_parameters(data,tokenized_command))
    return;

  if(tokenized_command->get_num_of_nodes()==1)
    data->get_disease_table()->num_current_patients();
  else if(tokenized_command->get_num_of_nodes()==2)
    data->get_disease_table()->num_current_patients((*tokenized_command)[1]);
}

