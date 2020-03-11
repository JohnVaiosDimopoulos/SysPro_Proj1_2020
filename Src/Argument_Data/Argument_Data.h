#ifndef PROJ_1_ARGUMENT_DATA_H
#define PROJ_1_ARGUMENT_DATA_H

#include <iostream>

class Argument_Data{
 private:
  std::string file_name;
  int disease_entries;
  int country_entries;
  int bucket_size;
 public:
  //getters-setters//
  std:: string get_file_name() const;
  void set_file_name(const std::string &fileName);
  int get_disease_entries() const;
  void set_disease_entries(int diseaseEntries);
  int get_country_entries() const;
  void set_country_entries(int countryEntries);
  int get_bucket_size() const;
  void set_bucket_size(int bucketSize);
  //for testing//
  friend std::ostream &operator<<(std::ostream &os, const Argument_Data &data);
};


#endif //PROJ_1_ARGUMENT_DATA_H
