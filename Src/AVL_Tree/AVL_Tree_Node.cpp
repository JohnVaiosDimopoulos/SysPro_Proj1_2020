#include "AVL_Tree_Node.h"

//==CONSTRUCTOR-DESTRUCTOR==//
AVL_Tree_Node::AVL_Tree_Node(const tree_info &info) : info(info) {
  this->left_child = NULL;
  this->right_child = NULL;
  this->height = 1;
}

AVL_Tree_Node::~AVL_Tree_Node() {
  if(this->right_child!=NULL)
    delete this->left_child;
  if(this->left_child!=NULL)
    delete this->right_child;
}
//==API==//

AVL_Tree_Node *AVL_Tree_Node::insert(AVL_Tree_Node *node, tree_info info) {
  if(node==NULL)
    return new AVL_Tree_Node(info);

  if(info.date<node->info.date)
    node->left_child = insert(node->left_child,info);
  else if(info.date > node->info.date || info.date == node->info.date)
    node->right_child = insert(node->right_child,info);


  node->height = 1 + get_max(get_height(node->left_child),get_height(node->right_child));
  int blc_factor = get_balance_factor(node);

  if(blc_factor > 1){
    if(info.date < node->left_child->info.date)
      return rotate_right(node);
    else if(info.date > node->left_child->info.date){
      node->left_child = rotate_left(node->left_child);
      return rotate_right(node);
    }
  }

  if(blc_factor < -1){
    if(info.date > node->right_child->info.date)
      return rotate_left(node);
    else if(info.date < node->right_child->info.date){
      node->left_child = rotate_right(node->left_child);
      return rotate_left(node);
    }
  }
  return node;
}

void AVL_Tree_Node::Print(AVL_Tree_Node *node, std::string indent, bool last) const {

  if(node!= nullptr){
    std:: cout<< indent;
    if(last){
      std::cout<<"R----";
      indent +="   ";
    }
    else{
      std::cout<<"L---";
      indent +="|   ";
    }

    std::cout<<node->info.date<<std::endl;
    Print(node->left_child,indent, false);
    Print(node->right_child,indent, true);
  }
}



//===INNER-FUNCTIONALITY==//
int AVL_Tree_Node::get_height(AVL_Tree_Node *node) {
  if(node==NULL)
    return 0;
  return node->height;
}

int AVL_Tree_Node::get_max(int a, int b)  {
  return (a > b) ? a : b;
}

int AVL_Tree_Node::get_balance_factor(AVL_Tree_Node *node) {
  if(node==NULL)
    return 0;
  return get_height(node->left_child) - get_height(node->right_child);
}

AVL_Tree_Node *AVL_Tree_Node::rotate_right(AVL_Tree_Node *y) {
  AVL_Tree_Node* x = y->left_child;
  AVL_Tree_Node* T2 = x->right_child;

  x->right_child = y;
  y->left_child = T2;

  y->height = get_max(get_height(y->left_child), get_height(y->right_child))+1;
  x->height = get_max(get_height(x->left_child), get_height(x->right_child))+1;
  return x;

}

AVL_Tree_Node *AVL_Tree_Node::rotate_left(AVL_Tree_Node *x) {
  AVL_Tree_Node* y = x->right_child;
  AVL_Tree_Node* T2 = y->left_child;

  y->left_child = x;
  x->right_child = T2;

  y->height = get_max(get_height(y->left_child), get_height(y->right_child))+1;
  x->height = get_max(get_height(x->left_child), get_height(x->right_child))+1;

  return y;



}





