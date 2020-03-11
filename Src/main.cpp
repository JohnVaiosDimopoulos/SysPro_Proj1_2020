#include <iostream>
#include "Argument_Manager/Argument_Manager.h"

int main(int argc,char** argv) {
  Argument_Manager Manager;
  Argument_Data data = Manager.manage_arguments(argc,argv);
  std::cout<<data<<std::endl;
  return 0;
}
