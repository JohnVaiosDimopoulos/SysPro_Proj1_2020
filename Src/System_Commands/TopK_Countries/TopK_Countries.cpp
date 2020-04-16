#include "TopK_Countries.h"

bool TopK_Countries::validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) {

  if(tokenized_command->get_num_of_nodes()!=3 && tokenized_command->get_num_of_nodes()!=5){
    std::cout<<"Invalid parameters"<<std::endl;
    return false;
  }
  else if(tokenized_command->get_num_of_nodes()==5
  && (tokenizer.str_to_Date((*tokenized_command)[3]) > tokenizer.str_to_Date((*tokenized_command)[4]))){
    std::cout<<"Invalid dates"<<std::endl;
    return false;
  }
  return true;
}


void TopK_Countries::Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) {
  if(!validate_parameters(data,tokenized_command))
    return;

  if(tokenized_command->get_num_of_nodes()==3)
    data->get_disease_table()->topk_countries(std::stoi((*tokenized_command)[1]),(*tokenized_command)[2]);
  else if(tokenized_command->get_num_of_nodes()==5)
    data->get_disease_table()->topk_countries(
        std::stoi((*tokenized_command)[1]),
        (*tokenized_command)[2],
        tokenizer.str_to_Date((*tokenized_command)[3]),
        tokenizer.str_to_Date((*tokenized_command)[3])
    );
}
