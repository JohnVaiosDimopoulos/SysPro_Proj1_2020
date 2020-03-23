#ifndef PROJ_1_INITIALIZER_H
#define PROJ_1_INITIALIZER_H

#include "../System_Data/System_Data.h"
#include "../Argument_Data/Argument_Data.h"

class Initializer {
 private:
  //==INNER-FUNCTIONALITY==//
  static bool open_file_for_read(const std::string &filename, std::fstream *file);
  static std::string* tokenize_record(std::string &record);
  static Date * str_to_Date(const std::string &date);
  static bool has_exit_date(const std::string&);
  static Patient_Record generate_record(const std::string *tokenized_string, const System_Data &system_data);

 public:
  //==API==//
  System_Data initalize(const Argument_Data &argument_data);


};

#endif //PROJ_1_INITIALIZER_H
