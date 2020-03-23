#include "Patients_List.h"

bool Patients_List::is_id_in_list(const int &id) const {
  list_node<Patient_Record>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_record_id() == id)
      return true;
    temp = temp->get_next();
  }
  return false;
}
