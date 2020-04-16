#include "AVL_Tree.h"

//==struct for topK==//


//==CONSTRUCTOR-DESTRUTOR==//
AVL_Tree::AVL_Tree() {
  this->root= nullptr;
  this->num_of_nodes = 0;
}


AVL_Tree::~AVL_Tree() {
  if(this->root!= nullptr)
    delete root;
}


//==API==//
void AVL_Tree::insert(list_node<Patient_Record> *node) {
  tree_info info{node,node->get_data().get_entry_date()};
  this->root = this->root->insert(this->root,info);
  this->num_of_nodes++;
}


void AVL_Tree::Print() {
  this->root->Print(root,"", false);
}

//==Inner-Functionality==//
Max_Heap *AVL_Tree::make_heap(Generic_List<topk_info> *list) {
  Max_Heap* heap = new Max_Heap();

  for(int i =0;i<list->get_num_of_nodes();i++)
    heap->heap_insert((*list)[i]);
  return heap;
}

//==Commands==//
int AVL_Tree::num_of_current_Patients() {
  int total_num=0;
  this->root->num_of_current_patients(&total_num);
  return total_num;
}

int AVL_Tree::global_disease_num(Date start, Date end) {
  int total_num=0;
  this->root->global_disease_stats(start, end, &total_num);
  return total_num;
}

int AVL_Tree::global_disease_num(Date start, Date end, std::string country) {
  int total_num=0;
  this->root->global_disease_stats(start, end, &total_num,country);
  return total_num;
}

Max_Heap * AVL_Tree::get_topk_diseases_heap() {
  Generic_List<topk_info> country_list;
  this->root->topk_diseases(&country_list);
  return make_heap(&country_list);
}

Max_Heap * AVL_Tree::get_topk_diseases_heap(Date start, Date end) {
  Generic_List<topk_info> country_list;
  this->root->topk_diseases(&country_list, start, end);
  return make_heap(&country_list);
}

Max_Heap * AVL_Tree::get_topk_countries_heap() {
  Generic_List<topk_info> disease_list;
  this->root->topk_countries(&disease_list);
  return make_heap(&disease_list);
}

Max_Heap * AVL_Tree::get_topk_countries_heap(Date start, Date end) {
  Generic_List<topk_info> disease_list;
  this->root->topk_countries(&disease_list, start, end);
  return make_heap(&disease_list);
}

//==Getter==//
int AVL_Tree::get_num_of_nodes() const {
  return num_of_nodes;
}





