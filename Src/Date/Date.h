#ifndef PROJ_1_DATE_H
#define PROJ_1_DATE_H

#include <ostream>
class Date {
 private:
  int year;
  int month;
  int day;
  int convert_to_timestamp(Date date);

 public:
  Date(int year, int month, int day);
  bool operator==(const Date &rhs) const;
  bool operator!=(const Date &rhs) const;
  int compare_with_other_date(Date);
  friend std::ostream &operator<<(std::ostream &os, const Date &date);

};

#endif //PROJ_1_DATE_H
