#include "Argument_Manager/Argument_Manager.h"
#include "Initializer/Initializer.h"


int main(int argc,char** argv) {
  Argument_Manager manager;
  Initializer initializer;
  Argument_Data argument_data = manager.manage_arguments(argc,argv);
  System_Data system_data = initializer.initalize(argument_data);
  return 0;
}
