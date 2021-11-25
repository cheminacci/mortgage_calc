
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calcMortgage(double principal, double rate, double years)
{	
	double total;
	rate++;	
	total = (principal) * pow(rate,years);
		
	return total;
}


double calcReducing(double principal, double rate, double years, double paid, FILE *fp)
 
{
	double total_remaining;
	total_remaining = principal;

	// Add 1 to the rate to keep the calculations simple. 	

	rate++;
	int i;


	for(i=0; i<years; i++)
	{
	    if(total_remaining>=0)
	    {		
		printf("\nThe total remaining in year %d is : %lf \n", i, total_remaining);
		fprintf(fp,"\nThe total remaining in year %d is : %lf \n", i, total_remaining);
		    
		total_remaining = ((total_remaining - paid) * rate);
	    }	
	}

	return total_remaining;


}
