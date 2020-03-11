#ifndef PROJ_1_ARGUMENT_MANAGER_H
#define PROJ_1_ARGUMENT_MANAGER_H
#include <iostream>
#include "../Argument_Data/Argument_Data.h"

class Argument_Manager {

 private:
  static bool check_and_set_file_name(int *index, char *const *argv, Argument_Data *data);
  static bool check_and_set_disease_number(int *index, char *const *argv, Argument_Data *data);
  static bool check_and_set_country_number(int *index, char *const *argv, Argument_Data *data);
  static bool check_and_set_bucket_size(int *index, char *const *argv, Argument_Data *data);
  static bool check_num_of_arguments(int);
  static Argument_Data get_data(int argc, char *const *argv, Argument_Data &data);

 public:
  //==API==//
  static Argument_Data manage_arguments(int, char**);
};

#endif //PROJ_1_ARGUMENT_MANAGER_H
