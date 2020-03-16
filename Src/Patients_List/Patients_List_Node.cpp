#include "Patients_List_Node.h"

//==GETTER-SETTER==//
Patients_List_Node *Patients_List_Node::get_next() const {
  return next;
}
void Patients_List_Node::set_next(Patients_List_Node *next) {
  this->next = next;
}

const Patient_Record &Patients_List_Node::getPatientRecord() const {
  return patient_record;
}

//==CONSTRUCTOR-DESTRUCTOR==//
Patients_List_Node::Patients_List_Node(Patient_Record &patient_record)
    : next(nullptr), patient_record(patient_record) {}


Patients_List_Node::~Patients_List_Node() {
  delete next;
}






