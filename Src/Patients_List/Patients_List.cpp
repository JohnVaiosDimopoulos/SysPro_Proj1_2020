#include "Patients_List.h"



//==INNER-FUNCTIONALITY==//
bool Patients_List::is_empty() {
  return this->head == nullptr;
}

//==CONSTRUCTOR-DESTRUCTOR==//
Patients_List::~Patients_List() {
  delete head;
}

Patients_List::Patients_List() {
  this->head = nullptr;
  this->tail = nullptr;
}

//==API==//
Patients_List_Node *Patients_List::insert_node(Patient_Record record) {
  Patients_List_Node* new_node = new Patients_List_Node(record);
  if(is_empty()){
    this->head = new_node;
    this->tail = new_node;
    return new_node;
  }
  this->tail->set_next(new_node);
  this->tail = new_node;
  return new_node;
}

Patients_List_Node *Patients_List::get_head() {
  return this->head;
}
Patients_List_Node *Patients_List::get_tail() {
  return this->tail;
}


