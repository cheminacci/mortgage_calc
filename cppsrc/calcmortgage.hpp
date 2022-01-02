// calcmortgage.hpp

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

double calc_mortgage(double principal, double rate, double years)
{	
	return (principal) * pow( (1.0+rate), years );
}

void calc_reducing(double principal, double rate, double years, double paid, std::string output_filename)
{

	std::ofstream log_calc ;
	log_calc.open(output_filename);	
	
	log_calc << "\n*********************** PAYMENT CALCULATOR *********************** \n";
	log_calc << "\n\nWhat is the principal? :\t" << principal;
	log_calc << "\n\nWhat is the annual rate? :\t" << rate;
	log_calc << "\n\nWhat is the number of years of the loan? :\t" << years;
	log_calc << "\n\nHow much do you pay off in a year? :\t" << paid << "\n\n";

	log_calc << "\n****************************************************************** \n";

	double total_remaining = principal;

	for(uint64_t i=0; i != years; i++)
	{
	    if(total_remaining>=0)
	    {		
    	    	std::cout << "\nThe total remaining in year " << i << " is : " << total_remaining << '\n';
		log_calc << "\nThe total remaining in year " << i << " is : " << total_remaining << '\n';
		total_remaining = ( (total_remaining - paid) * (1.0+rate) );
	    }	
	}

	if(total_remaining>=0)
	{	
		std::cout << "\nThe total amount owed is:\t" << total_remaining;
		log_calc << "\nThe total amount owed is:\t" << total_remaining;
	}

	else if(total_remaining<0)
	{
		std::cout << "\nThe total amount owed is: 0";
		log_calc << "\nThe total amount owed is: 0";
	}

	log_calc.close();

}
