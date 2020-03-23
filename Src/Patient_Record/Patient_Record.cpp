#include "Patient_Record.h"

//==GETTERS==//

int Patient_Record::get_record_id() const {
  return record_id;
}

const std::string &Patient_Record::get_first_name() const {
  return first_name;
}

const std::string &Patient_Record::get_last_name() const {
  return last_name;
}

const std::string &Patient_Record::get_disease_id() const {
  return disease_id;
}

const std::string &Patient_Record::get_country() const {
  return country;
}

const Date &Patient_Record::get_entry_date() const {
  return entry_date;
}

const Date &Patient_Record::get_exit_date() const {
  return exit_date;
}

//==CONSTRUCTOR==//
Patient_Record::Patient_Record(const int recordId,
                               const std::string &firstName,
                               const std::string &lastName,
                               const std::string &diseaseId,
                               const std::string &country,
                               Date *entryDate,
                               Date *exitDate)
    : record_id(recordId),
      first_name(firstName),
      last_name(lastName),
      disease_id(diseaseId),
      country(country),
      entry_date(*entryDate),
      exit_date(*exitDate) {}

//==OPERATORS==//

bool Patient_Record::operator==(const Patient_Record &rhs) const {
  return record_id == rhs.record_id &&
      first_name == rhs.first_name &&
      last_name == rhs.last_name &&
      disease_id == rhs.disease_id &&
      country == rhs.country &&
      entry_date == rhs.entry_date &&
      exit_date == rhs.exit_date;
}
bool Patient_Record::operator!=(const Patient_Record &rhs) const {
  return !(rhs == *this);
}

Patient_Record&Patient_Record::operator=(const Patient_Record &rhs) {
  this->record_id = rhs.record_id;
  this->first_name = rhs.first_name;
  this->last_name = rhs.last_name;
  this->country = rhs.country;
  this->entry_date = rhs.entry_date;
  this->exit_date = rhs.exit_date;
  return *this;
}




