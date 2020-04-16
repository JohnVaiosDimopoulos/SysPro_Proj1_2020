#ifndef PROJ_1_COMMAND_READER_H
#define PROJ_1_COMMAND_READER_H

#include "../System_Data/System_Data.h"
#include "../Tokenizer/Tokenizer.h"
class Command_Reader {
 private:
  Tokenizer tokenizer;
 public:
  void start_reading(System_Data* system_data);
};

#endif //PROJ_1_COMMAND_READER_H
