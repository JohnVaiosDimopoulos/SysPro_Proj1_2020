#ifndef PROJ_1_AVL_TREE_H
#define PROJ_1_AVL_TREE_H

#include <ostream>
#include "AVL_Tree_Node.h"
#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
class AVL_Tree {
 private:
  AVL_Tree_Node* root;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  AVL_Tree();
  virtual ~AVL_Tree();
  //==API==//
  void insert(list_node<Patient_Record>* node);
  void Print();
};

#endif //PROJ_1_AVL_TREE_H
