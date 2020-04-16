#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Argument_Manager.h"





Argument_Data Argument_Manager::manage_arguments(int argc, char** argv){

  check_num_of_arguments(argc);
  Argument_Data data;
  return get_data(argc, argv, data);
}

Argument_Data Argument_Manager::get_data(int argc, char *const *argv, Argument_Data &data) {

  for(int i = 1; i<argc; i++){
    if(check_and_set_file_name(&i, argv, &data))
      continue;
    else if(check_and_set_disease_number(&i, argv, &data))
      continue;
    else if(check_and_set_country_number(&i, argv, &data))
      continue;
    else if(check_and_set_bucket_size(&i, argv, &data))
      continue;
    else{
      std::cout<<"Error at argument handling"<<std::endl;
      exit(-1);
    }

  }
  return  data;
}

bool Argument_Manager::check_and_set_file_name(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-p")){
    (*index)++;
    data->set_file_name(argv[*index]);
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_disease_number(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-h1")){
    (*index)++;
    data->set_disease_entries(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_country_number(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-h2")){
    (*index)++;
    data->set_country_entries(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_bucket_size(int* index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-b")){
    (*index)++;
    data->set_bucket_size(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_num_of_arguments(int argc) {
  if(argc != 9){
    std::cout<<"Wrong number of arguments"<<std::endl;
    exit(-1);
  }
}


