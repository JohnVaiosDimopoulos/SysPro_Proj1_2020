#include <ctime>
#include "Date.h"
#include <iostream>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::convert_to_timestamp(Date date) {
  time_t rawtime;
  struct  tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  timeinfo->tm_year = date.year-1900;
  timeinfo->tm_mon = date.month -1;
  timeinfo->tm_mday = date.day;
  timeinfo->tm_hour = 0;
  timeinfo->tm_min = 0;
  timeinfo->tm_sec = 0;
  return  timegm(timeinfo);
}

int Date::compare_with_other_date(Date other_date) {
  int curr = convert_to_timestamp(*this);
  int other = convert_to_timestamp(other_date);
  std::cout<<*this<<":"<<curr<<" "<<other_date<<":"<<other<<std::endl;

  if(curr == other)
    return 0;
  else if (curr< other)
    return -1;
  else
    return 1;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
  os << "year: " << date.year << " month: " << date.month << " day: " << date.day;
  return os;
}

bool Date::operator==(const Date &rhs) const {
  return year == rhs.year &&
      month == rhs.month &&
      day == rhs.day;
}
bool Date::operator!=(const Date &rhs) const {
  return !(rhs == *this);
}
