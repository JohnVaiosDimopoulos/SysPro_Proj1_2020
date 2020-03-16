#ifndef PROJ_1_PATIENTS_LIST_NODE_H
#define PROJ_1_PATIENTS_LIST_NODE_H
#include <iostream>
#include "../Date/Date.h"
#include "../Patient_Record/Patient_Record.h"

class Patients_List_Node {
 private:
  Patients_List_Node* next;
  Patient_Record patient_record;

 public:

  //==CONSTRUCTOR-DESTRUCTOR==//
  virtual ~Patients_List_Node();
  Patients_List_Node(Patient_Record &patient_record);

  //==GETTER-SETTER==//
  void set_next(Patients_List_Node *next);
  const class Patient_Record &getPatientRecord() const;
  Patients_List_Node *get_next() const;



};

#endif //PROJ_1_PATIENTS_LIST_NODE_H
