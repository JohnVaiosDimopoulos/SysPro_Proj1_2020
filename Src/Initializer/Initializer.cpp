#include <fstream>
#include <sstream>
#include "Initializer.h"

//==INNER-FUNCTIONALITY==//

bool Initializer::open_file_for_read(const std::string &filename, std::fstream *file) {
  file->open(filename,std::fstream::in);
  return file->is_open();
}

std::string *Initializer::tokenize_record(std::string &record) {
  std::string* record_data = new std::string[7] ;
  int counter = 0;
  std::string token;
  std::istringstream ss(record);
  while(std::getline(ss,token,' ')){
    record_data[counter] = token;
    counter++;
  }
  return  record_data;
}

Date * Initializer::str_to_Date(const std::string &date) {
  std::string* record_data = new std::string[4] ;
  int counter = 0;
  std::string token;
  std::istringstream ss(date);
  while(std::getline(ss,token,'-')){
    record_data[counter] = token;
    counter++;
  }
  return new Date (std::stoi(record_data[3]),std::stoi(record_data[2]),std::stoi(record_data[0]));
}

bool Initializer::has_exit_date(const std::string& date) {
  return date == "-";
}

Patient_Record Initializer::generate_record(const std::string *tokenized_string, const System_Data &system_data) {


  //1. check if id is already in the list
  if(system_data.get_patient_records().is_id_in_list(std::stoi(tokenized_string[0]))){
    //exit
  }

  //2.check if exit date exists
  if(has_exit_date(tokenized_string[6])){
  }
  //3. check combatibility of entry and exit system_data
  Date* entry = str_to_Date(tokenized_string[5]);
  Date* exit = str_to_Date(tokenized_string[6]);

  if(exit > entry){
    //error
  }
  return {std::stoi(tokenized_string[0]),tokenized_string[1],tokenized_string[2],tokenized_string[3],tokenized_string[4],entry,exit};
}



//==API==//
System_Data Initializer::initalize(const Argument_Data &argument_data) {
  System_Data system_data(argument_data);
  std::fstream record_file;
  std::string buffer;
  //1.open file and return fp
  if(open_file_for_read(argument_data.get_file_name(),&record_file)){
    while (std::getline(record_file,buffer)){
      std::string* tokenized_string = tokenize_record(buffer);
      //2.make tha record
      Patient_Record record = generate_record(tokenized_string,system_data);
      //3.put it in the list
      list_node<Patient_Record>* node=system_data.get_patient_records().insert_node(record);
      //4.put it in the hash tables
//      system_data.get_country_table().insert(node,node->get_data().get_country());
//      system_data.get_disease_table().insert(node,node->get_data().get_disease_id());
     }
    return system_data;
    }
}




