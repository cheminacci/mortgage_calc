#include "calcmortgage.h"

int main()

{	char filename[30] ;

	printf("\n\nPlease enter the name of your file : ");
	scanf("%s", filename);

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
	
	amount = calcReducing(p,r,y,paid,logcalc);

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
