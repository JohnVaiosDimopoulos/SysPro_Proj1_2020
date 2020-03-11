#include "Argument_Data.h"

std::string Argument_Data::get_file_name() const {
  return file_name;
}

void Argument_Data::set_file_name(const std::string &fileName) {
  file_name = fileName;
}

int Argument_Data::get_disease_entries() const {
  return disease_entries;
}

void Argument_Data::set_disease_entries(int diseaseEntries) {
  disease_entries = diseaseEntries;
}

int Argument_Data::get_country_entries() const {
  return country_entries;
}

void Argument_Data::set_country_entries(int countryEntries) {
  country_entries = countryEntries;
}

int Argument_Data::get_bucket_size() const {
  return bucket_size;
}

void Argument_Data::set_bucket_size(int bucketSize) {
  bucket_size = bucketSize;
}

std::ostream &operator<<(std::ostream &os, const Argument_Data &data) {
  os << "file_name: " << data.file_name << " disease_entries: " << data.disease_entries << " country_entries: "
     << data.country_entries << " bucket_size: " << data.bucket_size;
  return os;
}
