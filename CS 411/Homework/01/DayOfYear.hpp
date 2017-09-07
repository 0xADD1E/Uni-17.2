#include <iostream>
class DayOfYear {
public:
  DayOfYear(int monthValue, int dayValue);
  DayOfYear(int monthValue);
  DayOfYear();

  friend std::ostream &operator<<(std::ostream &os, const DayOfYear &doy);
  friend std::istream &operator>>(std::istream &is, DayOfYear &doy);

  int setDayOfYear(int month, int day);
  int getMonth() const;
  int getDay() const;

  const DayOfYear operator+(const DayOfYear &doy); //
  const DayOfYear operator+(const int &numOfDays);
  const DayOfYear operator-();
  const bool operator==(const DayOfYear &doy);
  const bool operator>(const DayOfYear &doy);
  const bool operator<(const DayOfYear &doy);
  const DayOfYear &operator++();   // Prefix
  const DayOfYear operator++(int); // Postfix
  const DayOfYear &operator--();   // Prefix
  const DayOfYear operator--(int); // Postfix
  const int operator[](const int index);

private:
  int dayOfYear;
  static int monthLengths[];
};
const DayOfYear operator-(const DayOfYear &doy1, const DayOfYear &doy2);
