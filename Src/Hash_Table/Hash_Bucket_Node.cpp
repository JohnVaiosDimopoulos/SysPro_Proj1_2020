#include "Hash_Bucket_Node.h"

//==CONSTRUCTOR-DESTRUCTOR==//
Hash_Bucket_Node::Hash_Bucket_Node(int bucket_size) {
  num_of_elements = 0;
  max_elements = bucket_size/ sizeof(Node_element);
  elements = new Node_element[max_elements];
}

Hash_Bucket_Node::~Hash_Bucket_Node() {
  delete elements;
}

//==API==//
bool Hash_Bucket_Node::is_full() const {
  return num_of_elements == max_elements;
}

void Hash_Bucket_Node::insert(list_node<Patient_Record> *node, std::string &date) {
  elements[num_of_elements].name = date;
  elements[num_of_elements].date_tree.insert(node);
  num_of_elements++;
}

bool Hash_Bucket_Node::is_in_table(std::string &name) {
  for(int i=0;i<num_of_elements;i++){
    if(name == elements[i].name)
      return true;
  }
  return false;
}

void Hash_Bucket_Node::insert_date(list_node<Patient_Record> *node, std::string &name) {
  for(int i =0;i<num_of_elements;i++){
    if(name == elements[i].name){
      elements[i].date_tree.insert(node);
    }
  }
}



