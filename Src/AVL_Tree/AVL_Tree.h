#ifndef PROJ_1_AVL_TREE_H
#define PROJ_1_AVL_TREE_H

#include <ostream>
#include "AVL_Tree_Node.h"
#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
#include "../Max_Heap/Max_Heap.h"
class AVL_Tree {
 private:
  AVL_Tree_Node* root;
  int num_of_nodes;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  AVL_Tree();
  virtual ~AVL_Tree();
  //==API==//
  void insert(list_node<Patient_Record>* node);
  void Print();

  //==Getter==//
  int get_num_of_nodes() const;

  //==Inner_funv==//
  Max_Heap* make_heap(Generic_List<topk_info>* list);

  //==Commands==//
  int num_of_current_Patients();
  int global_disease_num(Date start, Date end);
  int global_disease_num(Date start, Date end,std::string country);
  Max_Heap *get_topk_diseases_heap();
  Max_Heap *get_topk_diseases_heap(Date start, Date end);
  Max_Heap *get_topk_countries_heap();
  Max_Heap *get_topk_countries_heap(Date start, Date end);
};

#endif //PROJ_1_AVL_TREE_H
