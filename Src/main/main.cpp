#include "../Argument_Manager/Argument_Manager.h"
#include "../Initializer/Initializer.h"
#include "../Command_Reader/Command_Reader.h"

int main(int argc,char** argv) {
  Argument_Manager manager;
  Initializer initializer;
  Command_Reader command_reader;
  System_Data system_data = initializer.initalize(manager.manage_arguments(argc,argv));
  command_reader.start_reading(&system_data);
  return 0;
}
