// calcmortgage.cpp

#include "calcmortgage.hpp"

int main()

{
	std::string filename;
	std::cout << "\n\nPlease enter the name of your file : ";
	
	getline(std::cin, filename);

	double principal;
	double rate;
	double years;
	double paid_per_year;

	std::cout << "\n\nWhat is the principal? : ";
	std::cin >> principal;
	std::cout << "\n\nWhat is the annual rate? : ";
	std::cin >> rate;	
	std::cout << "\n\nWhat is the number of years of the loan? : ";
	std::cin >> years;
	std::cout << "\n\nHow much do you pay off in a year? : ";
	std::cin >> paid_per_year;

	calc_reducing(principal, rate, years, paid_per_year, filename);

	return 0;
}
