#include "Global_Disease.h"
bool Global_Disease::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {

  if(tokenized_command->get_num_of_nodes()!=1 || tokenized_command->get_num_of_nodes()!=3){
    std::cout<<"Invalid parameters"<<std::endl;
    return false;
  }

  else if(tokenized_command->get_num_of_nodes()==7
      && (tokenizer.str_to_Date((*tokenized_command)[1]) > tokenizer.str_to_Date((*tokenized_command)[2]))){
    std::cout<<"Invalid dates"<<std::endl;
    return false;
  }
  return true;
}

void Global_Disease::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(tokenized_command->get_num_of_nodes()==1) {
    data->get_disease_table()->global_disease_stats();
  }
  else if(tokenized_command->get_num_of_nodes()==3) {
    Date start = tokenizer.str_to_Date((*tokenized_command)[1]);
    Date end = tokenizer.str_to_Date((*tokenized_command)[2]);
    data->get_disease_table()->global_disease_stats(start, end);
  }
}

