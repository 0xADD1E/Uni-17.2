#include "DayOfYear.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>
DayOfYear::DayOfYear(int monthValue, int dayValue)
    : dayOfYear(setDayOfYear(monthValue, dayValue)){};
DayOfYear::DayOfYear(int monthValue) : DayOfYear(monthValue, 1) {}
DayOfYear::DayOfYear() : DayOfYear(1) {}

int DayOfYear::monthLengths[] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};

std::istream &operator>>(std::istream &is, DayOfYear &doy) {
  int month = 1, day = 1;
  is >> month;
  is.get();
  is >> day;
  doy.dayOfYear = doy.setDayOfYear(month, day);
  return is;
}

std::ostream &operator<<(std::ostream &os, const DayOfYear &doy) {
  int month = doy.getMonth();
  std::string monthName;
  switch (month) {
  case 1:
    monthName = "January";
    break;
  case 2:
    monthName = "February";
    break;
  case 3:
    monthName = "March";
    break;
  case 4:
    monthName = "April";
    break;
  case 5:
    monthName = "May";
    break;
  case 6:
    monthName = "June";
    break;
  case 7:
    monthName = "July";
    break;
  case 8:
    monthName = "August";
    break;
  case 9:
    monthName = "September";
    break;
  case 10:
    monthName = "October";
    break;
  case 11:
    monthName = "November";
    break;
  case 12:
    monthName = "December";
    break;
  default:
    monthName = "Error in DayOfYear::output.";
  }
  std::cout << monthName << " " << doy.getDay();
  return os;
}

int DayOfYear::setDayOfYear(int month, int day) {
  assert(month <= 12);
  assert(day <= 31);

  int acc = day;
  for (int i = 0; i < (month - 1); i++) {
    acc += monthLengths[i];
  }
  return acc;
}
int DayOfYear::getMonth() const {
  int dayAcc = dayOfYear;
  int monthAcc = 0;
  while (dayAcc > 31) {
    dayAcc -= monthLengths[monthAcc];
    monthAcc++;
  }
  return ++monthAcc;
}
int DayOfYear::getDay() const {
  int dayAcc = dayOfYear;
  int monthAcc = 0;
  while (dayAcc > 31) {
    dayAcc -= monthLengths[monthAcc];
    monthAcc++;
  }
  return dayAcc;
}

const DayOfYear operator+(const DayOfYear& doy1, const DayOfYear& doy2) {
  DayOfYear nDay = DayOfYear();
  nDay.dayOfYear = (doy1.dayOfYear + doy2.dayOfYear) % 365;
  return nDay;
}
const DayOfYear operator+(const int& numOfDays, const DayOfYear& doy1) {
  DayOfYear nDay = DayOfYear();
  nDay.dayOfYear = (doy1.dayOfYear + numOfDays) % 365;
  return nDay;
}
const DayOfYear operator-(const DayOfYear& doy1) {
  DayOfYear nDay = DayOfYear();
  nDay.dayOfYear = 365 - doy1.dayOfYear;
  return nDay;
}
const bool operator==(const DayOfYear& doy1, const DayOfYear& doy2) {
  return doy1.dayOfYear == doy2.dayOfYear;
}
const bool operator>(const DayOfYear& doy1, const DayOfYear& doy2) {
  return doy1.dayOfYear > doy2.dayOfYear;
}
const bool operator<(const DayOfYear& doy1, const DayOfYear& doy2) {
  return doy1.dayOfYear < doy2.dayOfYear;
}
const DayOfYear& operator++(DayOfYear& doy1) {
  // Prefix Operator
  doy1.dayOfYear++;
  doy1.dayOfYear %= 365;
  return doy1;
}
const DayOfYear operator++(DayOfYear& doy1, int) {
  // Postfix Operator
  DayOfYear oDay = DayOfYear();
  oDay.dayOfYear = doy1.dayOfYear;
  doy1.dayOfYear++;
  doy1.dayOfYear %= 365;
  return oDay;
}
const DayOfYear& operator--(DayOfYear& doy1) {
  // Prefix Operator
  doy1.dayOfYear--;
  doy1.dayOfYear %= 365;
  return doy1;
}
const DayOfYear operator--(DayOfYear& doy1, int) {
  // Postfix Operator
  DayOfYear oDay = DayOfYear();
  oDay.dayOfYear = doy1.dayOfYear;
  doy1.dayOfYear--;
  doy1.dayOfYear %= 365;
  return oDay;
}
const int DayOfYear::operator[](const int index) {
  switch (index) {
  case 1:
    return getMonth();
  case 2:
    return getDay();
  case 3:
    return dayOfYear;
  default:
    return -1;
  }
}

const int operator-(const DayOfYear &doy1, const DayOfYear &doy2) {
  // Ugly bc not allowed to be member function
  int day1 = doy1.getDay(), day2 = doy2.getDay();
  int month1 = doy1.getMonth(), month2 = doy2.getMonth();
  if (month2 > month1 || day2 > day1){
      std::cout << "DayOfYear 2 Larger than DayOfYear 1 -- Not Subtracting" << std::endl;
      return 0;
  }
  int dayCount = day1 - day2;
  int monthLengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 0; i < month1 - 1; i++) {
    dayCount += monthLengths[i];
  }
  for (int i = 0; i < month2 - 1; i++) {
    dayCount -= monthLengths[i];
  }
  return dayCount;
}
