#ifndef PROJ_1_DISEASE_FREQUENCY_H
#define PROJ_1_DISEASE_FREQUENCY_H

#include "../../System_Data/System_Data.h"
#include "../../Tokenizer/Tokenizer.h"
#include "../System_Commands.h"
class Disease_Frequency : public System_Commands {
 public:
  void Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) override;
 private:
  bool validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) override;

};

#endif //PROJ_1_DISEASE_FREQUENCY_H
