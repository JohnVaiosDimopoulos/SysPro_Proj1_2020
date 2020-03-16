#ifndef PROJ_1_PATIENT_RECORD_H
#define PROJ_1_PATIENT_RECORD_H
#include <iostream>
#include "../Date/Date.h"
class Patient_Record {

 private:
  const int record_id;
  const std::string first_name;
  const std::string last_name;
  const std::string disease_id;
  const std::string country;
  const Date entry_date;
  const Date exit_date;

 public:
  //==CONSTRUCTOR==//
  Patient_Record(const int recordId,
                 const std::string &firstName,
                 const std::string &lastName,
                 const std::string &diseaseId,
                 const std::string &country,
                 Date *entryDate,
                 Date *exitDate);

  //==OPERATORS==//
  bool operator==(const Patient_Record &rhs) const;
  bool operator!=(const Patient_Record &rhs) const;


  //==GETTERS==//
  int get_record_id() const;
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_disease_id() const;
  const std::string &get_country() const;
  const Date &get_entry_date() const;
  const Date &get_exit_date() const;
};

#endif //PROJ_1_PATIENT_RECORD_H
