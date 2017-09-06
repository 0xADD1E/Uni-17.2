#include "DayOfYear.hpp"

int main( ) {
	DayOfYear d1 = DayOfYear();
	DayOfYear d2 = DayOfYear(2);
	DayOfYear d3 = DayOfYear(3, 5);
	DayOfYear d4 = DayOfYear(8, 13);

  std::cout << d1<<std::endl;
	std::cout << d2<<std::endl;
	std::cout << (d1 + d2) << std::endl;
	std::cout << (d4 + d4) << std::endl;
	std::cout << (d1 + 1) << std::endl;
	std::cout << (d4 + 200) << std::endl;
	std::cout << (d4 - d3) << std::endl;
	std::cout << (d1 - d4) << std::endl;
	std::cout << (-d2) << std::endl;
	std::cout << (d1 == d1) << std::endl;
	std::cout << (d1 == d2) << std::endl;
	std::cout << (d1 < d2) << std::endl;
	std::cout << (d2 < d1) << std::endl;
	std::cout << (d1 > d2) << std::endl;
	std::cout << (d2 > d1) << std::endl;
  std::cout << (++d1) << std::endl;
	std::cout << (d2++) << std::endl;
	std::cout << (d2++) << std::endl;
	std::cout << (--d1) << std::endl;
	std::cout << (d2--) << std::endl;
	std::cout << (d2--) << std::endl;
	std::cout << (d4[1]) << std::endl;
	std::cout << (d4[2]) << std::endl;
	std::cout << (d4[3]) << std::endl;
 	return 0;
}
