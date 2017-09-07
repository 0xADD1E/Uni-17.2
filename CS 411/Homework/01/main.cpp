#include "DayOfYear.hpp"

int main() {
  DayOfYear d1 = DayOfYear();
  DayOfYear d2 = DayOfYear(2);
  DayOfYear d3 = DayOfYear(3, 5);
  DayOfYear d4 = DayOfYear(12, 31);

  std::cout << "Starting Values (d1 - d4)" << std::endl
            << d1 << std::endl
            << d2 << std::endl
            << d3 << std::endl
            << d4 << std::endl
            << std::endl;
  std::cout << "Addition Operations" << std::endl
            << "d1 + d2:  " << (d1 + d2) << std::endl
            << "d1 + d4:  " << (d1 + d4) << std::endl
            << "d1 + 1:   " << (d1 + 1) << std::endl
            << "d4 + 2:   " << (d4 + 2) << std::endl
            << std::endl;
  std::cout << "Subtraction Operations" << std::endl
            << "d4 - d3:  " << (d4 - d3) << std::endl
            << "d1 - d4:  " << (d1 - d4) << std::endl
            << "-d2:      " << (-d2) << std::endl
            << std::endl;
  std::cout << "Comparison Operations" << std::endl
            << "d1 == d1: " << (d1 == d1) << std::endl
            << "d1 == d2: " << (d1 == d2) << std::endl
            << "d1 < d2:  " << (d1 < d2) << std::endl
            << "d2 < d1:  " << (d2 < d1) << std::endl
            << "d1 > d2:  " << (d1 > d2) << std::endl
            << "d2 > d1:  " << (d2 > d1) << std::endl
            << std::endl;
  std::cout << "Increment/Decrement Operations" << std::endl
            << "++d1:     " << (++d1) << std::endl
            << "d1:       " << (d1) << std::endl
            << "d2++:     " << (d2++) << std::endl
            << "d2:       " << (d2) << std::endl
            << "--d1:     " << (--d1) << std::endl
            << "d1:       " << (d1) << std::endl
            << "d2--:     " << (d2--) << std::endl
            << "d2:       " << (d2) << std::endl
            << std::endl;
  std::cout << "Index Operations" << std::endl
            << "d3[1]:    " << (d3[1]) << std::endl
            << "d3[2]:    " << (d3[2]) << std::endl
            << "d3[3]:    " << (d3[3]) << std::endl
            << std::endl;
  std::cout << "Input/Output" << std::endl
            << "Please input a new date for d1 (format: 'M/D')\n->";
  std::cin >> d1;
  std::cout << "d1:       " << d1 << std::endl;
  return 0;
}
