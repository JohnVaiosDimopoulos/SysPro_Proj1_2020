#ifndef PROJ_1_PATIENTS_LIST_H
#define PROJ_1_PATIENTS_LIST_H
#include "Patients_List_Node.h"


class Patients_List {
 private:
  Patients_List_Node* head;
  Patients_List_Node* tail;
  //==INNER-FUNCTIONALITY==//
  bool is_empty();
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  Patients_List();
  virtual ~Patients_List();

  //==API==//
  Patients_List_Node* insert_node(Patient_Record);
  Patients_List_Node* get_head();
  Patients_List_Node* get_tail();
};

#endif //PROJ_1_PATIENTS_LIST_H
