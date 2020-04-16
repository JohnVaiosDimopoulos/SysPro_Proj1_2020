#include <fstream>
#include "Initializer.h"

//==INNER-FUNCTIONALITY==//

bool Initializer::open_file_for_read(const std::string &filename, std::fstream *file) {
  file->open(filename,std::fstream::in);
  return file->is_open();
}

bool Initializer::has_exit_date(const std::string& date) {
  return date != "-";
}

//==API==//
System_Data Initializer::initalize(const Argument_Data &argument_data) {
  System_Data system_data(argument_data);
  std::fstream record_file;
  std::string buffer;
  //1.open file and return fp
  if(!open_file_for_read(argument_data.get_file_name(),&record_file)){
    exit(-1);
  }

  while (std::getline(record_file,buffer)){
    std::string* tokenized_string = tokenizer.tokenize_record(buffer);

    //1. check if id is already in the list
    if(system_data.get_patient_records_ptr()->is_id_in_list(std::stoi(tokenized_string[0]))){
      exit(-1);
    }

    //2.check if exit date exists
    Date exit_date{0,0,0};
    if(has_exit_date(tokenized_string[6]))
      exit_date =  tokenizer.str_to_Date(tokenized_string[6]);
    //3. check combatibility of entry and exit system_data
    Date entry_date = tokenizer.str_to_Date(tokenized_string[5]);

    if(exit_date < entry_date && exit_date != Date{0,0,0}){
      exit(-1);
    }

    Patient_Record record{std::stoi(tokenized_string[0]), tokenized_string[1], tokenized_string[2], tokenized_string[3], tokenized_string[4], entry_date, exit_date};

    //3.put it in the list
    list_node<Patient_Record>* node= system_data.get_patient_records_ptr()->insert_node(record);
    //4.put it in the hash tables
      system_data.get_country_table()->insert(node,node->get_data().get_country());
      system_data.get_disease_table()->insert(node,node->get_data().get_disease_id());
    delete[] tokenized_string;

   }
  return system_data;

}




