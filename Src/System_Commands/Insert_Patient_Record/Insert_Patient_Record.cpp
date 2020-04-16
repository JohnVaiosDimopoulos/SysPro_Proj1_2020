#include "Insert_Patient_Record.h"

bool Insert_Patient_Record::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {

  if(tokenized_command->get_num_of_nodes() != 7 && tokenized_command->get_num_of_nodes() != 8 ){
    std::cout<<"Wrong parameters"<<std::endl;
    return false;
  }

  else if(data->get_patient_records_ptr()->is_id_in_list(std::stoi((*tokenized_command)[1]))) {
    std::cout<<"The id already exists"<<std::endl;
    return false;
  }

  else if(tokenized_command->get_num_of_nodes()==8
  &&(tokenizer.str_to_Date((*tokenized_command)[6]) > tokenizer.str_to_Date((*tokenized_command)[7]))){
    std::cout<<"The dates are invalid"<<std::endl;
    return false;
  }
  return true;


}

void Insert_Patient_Record::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {

  if(!validate_parameters(data,tokenized_command))
    return;

    Patient_Record record(
        std::stoi((*tokenized_command)[1]),
        (*tokenized_command)[2],
        (*tokenized_command)[3],
        (*tokenized_command)[4],
        (*tokenized_command)[5],
        tokenizer.str_to_Date((*tokenized_command)[6]),
        {0,0,0});

    if(tokenized_command->get_num_of_nodes()==7)
      record.setExitDate(tokenizer.str_to_Date((*tokenized_command)[7]));


    list_node<Patient_Record>* node = data->get_patient_records_ptr()->insert_node(record);
    data->get_disease_table()->insert(node,record.get_disease_id());
    data->get_disease_table()->insert(node,record.get_country());

    std::cout<<"Record added"<<std::endl;

}

