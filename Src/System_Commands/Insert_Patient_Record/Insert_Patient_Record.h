#ifndef PROJ_1_INSERT_PATIENT_RECORD_H
#define PROJ_1_INSERT_PATIENT_RECORD_H

#include "../../System_Data/System_Data.h"
#include "../../Tokenizer/Tokenizer.h"
#include "../System_Commands.h"
class Insert_Patient_Record: public System_Commands {
 public:
  void Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) override;
 protected:
  bool validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) override;
};

#endif //PROJ_1_INSERT_PATIENT_RECORD_H
