#ifndef PROJ_1_TOKENIZER_H
#define PROJ_1_TOKENIZER_H

#include <string>
#include "../Date/Date.h"
#include "../Generic_List/Generic_List.h"

class Tokenizer {
 public:
  std::string* tokenize_record(std::string &record);
  Date str_to_Date(const std::string &date);
  Generic_List<std::string> tokenize_command(std::string &command);
};

#endif //PROJ_1_TOKENIZER_H
