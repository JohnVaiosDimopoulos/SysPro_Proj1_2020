#ifndef PROJ_1_SYSTEM_COMMANDS_H
#define PROJ_1_SYSTEM_COMMANDS_H

#include "../System_Data/System_Data.h"
#include "../Tokenizer/Tokenizer.h"
class System_Commands {
 protected:
  Tokenizer tokenizer;
  virtual bool validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) = 0;
 public:
  virtual void Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) = 0;
};

#endif //PROJ_1_SYSTEM_COMMANDS_H
