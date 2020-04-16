#ifndef PROJ_1_MAX_HEAP_H
#define PROJ_1_MAX_HEAP_H

#include "Max_heap_node.h"
#include "../AVL_Tree/AVL_Tree_Node.h"
class Max_Heap {
 private:
  Max_heap_node* root;
  topk_info Pop_Max();
 public:
  //==Constructor-Destructor==//
  Max_Heap();
  virtual ~Max_Heap();
  //==API==//
  void heap_insert(topk_info);
  void Print_Max_K(int k);

};

#endif //PROJ_1_MAX_HEAP_H
