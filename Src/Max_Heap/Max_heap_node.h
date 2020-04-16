#ifndef PROJ_1_MAX_HEAP_NODE_H
#define PROJ_1_MAX_HEAP_NODE_H

#include "../AVL_Tree/AVL_Tree_Node.h"
class Max_heap_node {
 private:
  topk_info info;
  int height;
  Max_heap_node* left_child;
  Max_heap_node* right_child;

  //==Private-functionality==//
  bool has_no_children();
  int get_height(Max_heap_node* node);
  int get_max(int a,int b);
  void calculate_high(Max_heap_node* current_node);
  Max_heap_node* get_max_node(Max_heap_node* a,Max_heap_node* b);
  void heapify(Max_heap_node* current,Max_heap_node* child);
  void insert_left(topk_info info, Max_heap_node* current_node);
  void insert_right(topk_info info, Max_heap_node* current_node);
  Max_heap_node* find_last(Max_heap_node* current_node);
  void reheapify(Max_heap_node* current_node);

 public:
  //==Constructor-Destructor==//
  Max_heap_node(const topk_info &info);
  virtual ~Max_heap_node();

  //==API==//
  Max_heap_node* insert(topk_info info, Max_heap_node *current_node);
  topk_info pop(Max_heap_node *current_node);

  //==Getter==//
  const topk_info &get_info() const;
  //==Setter==//
  void set_info(const topk_info &info);

};



#endif //PROJ_1_MAX_HEAP_NODE_H
