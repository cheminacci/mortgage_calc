#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

	This is a compounding function. Can be used to determine investment or debt
	growth over time.

*/

double calcMortgage(double principal, double rate, double years)

{	
	double total;
	rate++;	
	total = (principal) * pow(rate,years);
		
	return total;
}

/*
	
	 This function subtracts the annual amount paid while adding the interest
   	 to the amount remaining each year. It repeats this until the loan is paid off
	 or has reached the set number of years allotted to pay.

*/

double calcReducing(double principal, double rate, int years, double paid, FILE *fp, char *name)
 
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

int main()

{	char filename[30];

	printf("\n\nPlease enter the name of your file : ");
	scanf("%s", &filename);

	FILE *logcalc;

	logcalc = fopen(filename,"w");	

	double p;
	double r;
	double y;
	double paid;
	double amount;

	printf("\n\nWhat is the principal? : ");
	scanf("%lf", &p);
	printf("\n\nWhat is the annual rate? : ");
	scanf("%lf", &r);
	printf("\n\nWhat is the number of years of the loan? : ");
	scanf("%lf", &y);
	printf("\n\nHow much do you pay off in a year? : ");
	scanf("%lf", &paid);
	
	fprintf(logcalc,"\n*********************** PAYMENT CALCULATOR *********************** \n");
	fprintf(logcalc,"\n\nWhat is the principal? : %lf",p);
	fprintf(logcalc,"\n\nWhat is the annual rate? : %lf",r);
	fprintf(logcalc,"\n\nWhat is the number of years of the loan? : %lf",y);
	fprintf(logcalc,"\n\nHow much do you pay off in a year? : %lf \n\n",paid);

	fprintf(logcalc,"\n****************************************************************** \n");
	
	amount = calcReducing(p,r,y,paid,logcalc,filename);

	if(amount>=0)

	{	
		printf("\nThe total amount owed is: %f\n", amount);
		fprintf(logcalc,"\nThe total amount owed is: %f\n", amount);
	}

	else if(amount<0)
	{
		printf("\nThe total amount owed is: 0");
		fprintf(logcalc,"\nThe total amount owed is: 0");
	}

	fclose(logcalc);

	return 0;
}
