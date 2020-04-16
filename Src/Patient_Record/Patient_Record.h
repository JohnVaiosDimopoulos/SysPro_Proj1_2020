#ifndef PROJ_1_PATIENT_RECORD_H
#define PROJ_1_PATIENT_RECORD_H
#include <iostream>
#include "../Date/Date.h"
class Patient_Record {

 private:
  int record_id;
  std::string first_name;
  std::string last_name;
  std::string disease_id;
  std::string country;
  Date entry_date;
  Date exit_date;

 public:
  //==CONSTRUCTOR==//
  Patient_Record(const int recordId,
                 const std::string &firstName,
                 const std::string &lastName,
                 const std::string &diseaseId,
                 const std::string &country,
                 Date entryDate,
                 Date exitDate);

  //==OPERATORS==//
  bool operator==(const Patient_Record &rhs) const;
  bool operator!=(const Patient_Record &rhs) const;
  Patient_Record& operator=(const Patient_Record &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Patient_Record &record);

  //==GETTERS==//
  int get_record_id() const;
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_disease_id() const;
  const std::string &get_country() const;
  const Date &get_entry_date() const;
  const Date &get_exit_date() const;
  bool has_exit_date() const;
  //==SETTER==//
  void setExitDate(const Date &exitDate);
};

#endif //PROJ_1_PATIENT_RECORD_H
