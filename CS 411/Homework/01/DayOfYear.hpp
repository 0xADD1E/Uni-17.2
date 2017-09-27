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

  const friend DayOfYear operator+(const DayOfYear&, const DayOfYear&);
  const friend DayOfYear operator+(const int&, const DayOfYear&);
  const friend DayOfYear operator-(const DayOfYear&);
  const friend bool operator==(const DayOfYear&, const DayOfYear&);
  const friend bool operator>(const DayOfYear&, const DayOfYear&);
  const friend bool operator<(const DayOfYear&, const DayOfYear&);
  const friend DayOfYear& operator++(DayOfYear&);      // Prefix
  const friend DayOfYear  operator++(DayOfYear&, int); // Postfix
  const friend DayOfYear& operator--(DayOfYear&);      // Prefix
  const friend DayOfYear  operator--(DayOfYear&, int); // Postfix
  const int operator[](const int index);

private:
  int dayOfYear;
  static int monthLengths[];
};
const int operator-(const DayOfYear&, const DayOfYear&);
