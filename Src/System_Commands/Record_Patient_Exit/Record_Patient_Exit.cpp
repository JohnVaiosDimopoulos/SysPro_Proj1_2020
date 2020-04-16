#include "Record_Patient_Exit.h"

bool Record_Patient_Exit::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(tokenized_command->get_num_of_nodes()!=3){
    std::cout<<"Wrong parameters"<<std::endl;
    return false;
  }

  else if(!data->get_patient_records_ptr()->is_id_in_list(std::stoi((*tokenized_command)[1]))){
    std::cout<<"The id does not exist"<<std::endl;
    return false;
  }
  return true;
}

void Record_Patient_Exit::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {


  if(!validate_parameters(data,tokenized_command))
    return;

  list_node<Patient_Record>* node = data->get_patient_records_ptr()->get_patient(std::stoi((*tokenized_command)[1]));
  if(node!=NULL)
    node->get_data().setExitDate(tokenizer.str_to_Date((*tokenized_command)[2]));

  std::cout<<"Record Updated"<<std::endl;


}

