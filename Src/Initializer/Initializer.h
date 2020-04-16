#ifndef PROJ_1_INITIALIZER_H
#define PROJ_1_INITIALIZER_H

#include "../System_Data/System_Data.h"
#include "../Argument_Data/Argument_Data.h"
#include "../Tokenizer/Tokenizer.h"

class Initializer {
 private:
  Tokenizer tokenizer;
  //==INNER-FUNCTIONALITY==//
  bool open_file_for_read(const std::string &filename, std::fstream *file);
  bool has_exit_date(const std::string&);
  void record_validity_check(std::string* tokenized_string);

 public:
  //==API==//
  System_Data initalize(const Argument_Data &argument_data);


};

#endif //PROJ_1_INITIALIZER_H
