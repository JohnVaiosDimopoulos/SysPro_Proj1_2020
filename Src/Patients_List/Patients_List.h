
#ifndef PROJ_1_PATIENTS_LIST_H
#define PROJ_1_PATIENTS_LIST_H

#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
class Patients_List: public Generic_List<Patient_Record> {
 public:
  //==API==//
  bool is_id_in_list(const int& id) const;
  list_node<Patient_Record>* get_patient(const int& id);

};

#endif //PROJ_1_PATIENTS_LIST_H
