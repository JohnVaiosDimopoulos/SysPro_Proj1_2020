#include "AVL_Tree.h"
//==CONSTRUCTOR-DESTRUTOR==//
AVL_Tree::AVL_Tree() {
  this->root= nullptr;
}


AVL_Tree::~AVL_Tree() {
  if(this->root!= nullptr)
    delete root;
}

//==API==//
void AVL_Tree::insert(list_node<Patient_Record> *node) {
  tree_info info{node,node->get_data().get_entry_date()};
  this->root = this->root->insert(this->root,info);
}


void AVL_Tree::Print() {
  this->root->Print(root,"", false);
}


