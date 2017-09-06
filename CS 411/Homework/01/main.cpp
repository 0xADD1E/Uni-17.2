#include <iostream>
#include "DayOfYear.hpp"

int main( ) {
	DayOfYear date1(2, 28), date2(12, 31), date3;
  std::cout << "Initialized dates:\n";
  date1.output( ); std::cout << std::endl;
  date2.output( ); std::cout << std::endl;
  date3.output( ); std::cout << std::endl;
  date1 = DayOfYear(10, 32);
  std::cout << "date1 reset to the following:\n";
  date1.output( ); std::cout << std::endl;
 	return 0;
}
