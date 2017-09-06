#include "DayOfYear.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
DayOfYear::DayOfYear(int monthValue, int dayValue): dayOfYear(setDayOfYear(monthValue, dayValue)){};
DayOfYear::DayOfYear(int monthValue): DayOfYear(monthValue, 1){}
DayOfYear::DayOfYear() : DayOfYear(1) {}

int DayOfYear::monthLengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void DayOfYear::input() {
  int month = 1, day = 1;
  std::cout << "Enter the month as a number: ";
  std::cin >> month;
  std::cout << "Enter the day of the month: ";
  std::cin >> day;
  setDayOfYear(month, day);
}

void DayOfYear::output( ){
  int month = getMonth();
  std::string monthName;
  switch (month){
    case 1:
    monthName = "January"; break;
    case 2:
    monthName = "February"; break;
    case 3:
    monthName = "March"; break;
    case 4:
    monthName = "April"; break;
    case 5:
    monthName = "May"; break;
    case 6:
    monthName = "June"; break;
    case 7:
    monthName = "July"; break;
    case 8:
    monthName = "August"; break;
    case 9:
    monthName = "September"; break;
    case 10:
    monthName = "October"; break;
    case 11:
    monthName = "November"; break;
    case 12:
    monthName = "December"; break;
    default:
    monthName = "Error in DayOfYear::output.";
  }
  std::cout << monthName << " " << getDay();
}

int DayOfYear::setDayOfYear(int month, int day){
  assert(month <= 12);
  assert(day <= 31);

  int acc = day;
  for(int i = 0; i < (month - 1); i++){
    acc += monthLengths[i];
  }
  //in python this would be `return sum(monthLengths[:month-1])+day`
  return acc;
}
int DayOfYear::getMonth(){
  int dayAcc = dayOfYear;
  int monthAcc = 1;
  while(dayAcc > 31){
    dayAcc -= monthLengths[monthAcc];
    monthAcc++;
  }
  return monthAcc;
}
int DayOfYear::getDay(){
  int dayAcc = dayOfYear;
  int monthAcc = 1;
  while(dayAcc > 31){
    dayAcc -= monthLengths[monthAcc];
    monthAcc++;
  }
  return dayAcc;
}
