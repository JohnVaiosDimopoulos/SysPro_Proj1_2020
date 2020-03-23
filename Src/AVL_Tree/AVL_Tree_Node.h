
#ifndef PROJ_1_AVL_TREE_NODE_H
#define PROJ_1_AVL_TREE_NODE_H

#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
struct {
  list_node<Patient_Record>* node;
  Date date;
} typedef tree_info ;

class AVL_Tree_Node {
 private:
  tree_info info;
  AVL_Tree_Node* left_child;
  AVL_Tree_Node* right_child;
  int height;

  //==INNER-FUNCTIONALITY==//
  static int get_height(AVL_Tree_Node* node);
  static int get_max(int a,int b);
  static int get_balance_factor(AVL_Tree_Node* node);
  AVL_Tree_Node* rotate_right(AVL_Tree_Node* y);
  AVL_Tree_Node* rotate_left(AVL_Tree_Node* x);
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  AVL_Tree_Node(const tree_info &info);
  virtual ~AVL_Tree_Node();
  //==API==//
 AVL_Tree_Node* insert(AVL_Tree_Node* node, tree_info info);
 void Print(AVL_Tree_Node* node, std::string indent, bool last) const ;
};

#endif //PROJ_1_AVL_TREE_NODE_H
