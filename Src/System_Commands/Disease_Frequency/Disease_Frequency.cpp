#include "Disease_Frequency.h"

bool Disease_Frequency::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(tokenized_command->get_num_of_nodes()!=4 && tokenized_command->get_num_of_nodes()!=5){

    std::cout<<"Wrong parameters"<<std::endl;
    return false;
  }

  else if(tokenized_command->get_num_of_nodes()==4
  && (tokenizer.str_to_Date((*tokenized_command)[2]) > tokenizer.str_to_Date((*tokenized_command)[3]))){
    std::cout<<"The dates are invalid"<<std::endl;
    return false;
  }

  else if(tokenized_command->get_num_of_nodes()==5
  && (tokenizer.str_to_Date((*tokenized_command)[2]) > tokenizer.str_to_Date((*tokenized_command)[3]))) {
    std::cout<<"The dates are invalid"<<std::endl;
    return false;
  }
  return true;

}

void Disease_Frequency::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {

  if(!validate_parameters(data,tokenized_command))
    return;
  if(tokenized_command->get_num_of_nodes()==4)

    data->get_disease_table()->diseaseFrequency(
        (*tokenized_command)[1],
        tokenizer.str_to_Date((*tokenized_command)[2]),
        tokenizer.str_to_Date((*tokenized_command)[3]));

  else if(tokenized_command->get_num_of_nodes()==5){

    data->get_disease_table()->diseaseFrequency(
        (*tokenized_command)[1],
        tokenizer.str_to_Date((*tokenized_command)[2]),
        tokenizer.str_to_Date((*tokenized_command)[3]),
        (*tokenized_command)[4]
        );
  }

}

