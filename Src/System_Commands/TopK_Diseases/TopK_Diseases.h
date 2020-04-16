
#ifndef PROJ_1_TOPK_DISEASES_H
#define PROJ_1_TOPK_DISEASES_H

#include "../../System_Data/System_Data.h"
#include "../System_Commands.h"
class TopK_Diseases: public System_Commands {
 public:
  void Execute_Command(System_Data *data, Generic_List<std::string> *tokenized_command) override;
 protected:
  bool validate_parameters(System_Data *data, Generic_List<std::string> *tokenized_command) override;
};

#endif //PROJ_1_TOPK_DISEASES_H
