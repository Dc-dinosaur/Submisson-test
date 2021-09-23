#include<stdio.h>
#include<math.h>
#include<string.h>

int main() {

	double P, r, B, R, t2;
	int t, n, years, months, tstart, tend, x;
	char option[10];

	printf("1. Enter P, r, n, t. Find B.\n");
	printf("2. Enter r, n, t, B. Find P.\n");
	printf("3. Enter n, t, P, B. Find r.\n");
	printf("4. Enter t, r, P, B. Find n.\n");
	printf("5. Enter n, r, P, B. Find t.\n");
	printf("6. Generate a report for given year interval.\n");
	printf("7. Compare two accounts.\n");

	x = 0;       //Condition for the Do-while loop.
	do {
		printf("\nEnter your option: N [n={1,2,3,4,5,6,7}] : ");
		scanf("%s", option);       //Use string because user may accidentally enter input with the wrong data type used.
		printf("\n");              //Prevent misinterpretation of input.


		if (strcmp(option, "1") == 0)     //using the strcmp() function to compare two strings.
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Principal, P (in RM)           : ");
			scanf("%lf", &P);
			printf("Annual interest rate, R (in %%) : ");
			scanf("%lf", &R);
			printf("Compound ratio, n              : ");
			scanf("%d", &n);
			printf("Duration, t (in years)         : ");
			scanf("%d", &t);

			r = R / 100;      //Convert percentage form to decimal form for calculation.
			B = P * pow(1 + (r / n), (double)n * t);
			printf("***********************************************\n");
			printf("The balance after %dyears is RM%.2lf. \n", t, B);
			printf("***********************************************\n");
		}



		else if (strcmp(option, "2") == 0)
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Balance, B (in RM)             : ");
			scanf("%lf", &B);
			printf("Annual interest rate, R (in %%) : ");
			scanf("%lf", &R);
			printf("Compound ratio, n              : ");
			scanf("%d", &n);
			printf("Duration, t (in years)         : ");
			scanf("%d", &t);

			r = R / 100;
			P = B / pow(1 + (r / n), (double)n * t);
			printf("*******************************************\n");
			printf("The principal invested is RM%.2lf. \n", P);
			printf("*******************************************\n");
		}



		else if (strcmp(option, "3") == 0)
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Balance, B (in RM)    : ");
			scanf("%lf", &B);
			printf("Principal, P (in RM)  : ");
			scanf("%lf", &P);
			printf("Compound ratio, n     : ");
			scanf("%d", &n);
			printf("Duration, t (in years): ");
			scanf("%d", &t);

			r = n * (pow((B / P), (1 / ((double)n * t))) - 1);
			printf("********************************************\n");
			printf("The interest rate is %.2lf%%\n", r * 100);
			printf("********************************************\n");
		}



		else if (strcmp(option, "4") == 0)
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Balance, B (in RM)             : ");
			scanf("%lf", &B);
			printf("Principal, P (in RM)           : ");
			scanf("%lf", &P);
			printf("Annual interest rate, R (in %%) : ");
			scanf("%lf", &R);
			printf("Duration, t (in years)         : ");
			scanf("%d", &t);

			//Iteration method
			double lastN, N, tolerence;
			tolerence = 0.000001;
			N = 4;         //Assign a starting number of N for iteration. (4 is a good starting number)
			r = R / 100;
			do
			{
				lastN = N;
				N = (log(B / P)) / (t * log(1 + r / lastN));
				//printf("Checking N = %lf\n", N);
			} while (fabs(N - lastN) > tolerence);   //fabs() to make the difference always positive.

			printf("**********************************************************************************\n");
			printf("The compound ratio is %.0lf.\n", N);
			printf("**********************************************************************************\n");
		}



		else if (strcmp(option, "5") == 0)
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Balance, B (in RM)             : ");
			scanf("%lf", &B);
			printf("Principal, P (in RM)           : ");
			scanf("%lf", &P);
			printf("Annual interest rate, R (in %%) : ");
			scanf("%lf", &R);
			printf("Compound ratio, n              : ");
			scanf("%d", &n);

			r = R / 100;
			t2 = (log(B / P)) / ((double)n * (log(1 + (r / (double)n))));  //Finding years with decimals.
			years = (int)floor(t2);                                        //Finding exact years by eliminating the decimals.
			months = (int)ceil((t2 - (double)years) * 12.0);               //Use years decimals to find months.

			printf("**********************************************************************************\n");
			if (months == 12)   //Because sometimes the answer may round up to 12.
			{
				printf("It will take %dyear(s) to reach the balance RM%.2lf\n", years + 1, B);
			}
			else if (years == 0)   //In case it took less than a year, but the posibility is very low.
			{
				printf("It will take %dmonth(s) to reach the balance RM%.2lf\n", months, B);
			}
			else
			{
				printf("It will takes %dyear(s) and %dmonth(s) to reach the balance RM%.2lf\n", years, months, B);
			}
			printf("**********************************************************************************\n");
		}



		else if (strcmp(option, "6") == 0)
		{
			x = 1;
			printf("Please key in the particulars below\n");
			printf("Principal, P (in RM)           :");
			scanf("%lf", &P);
			printf("Annual interest rate, R (in %%) : ");
			scanf("%lf", &R);
			printf("Compound ratio, n              : ");
			scanf("%d", &n);

			printf("\nTo generate the report,\n");
			printf("Enter the start year: ");
			scanf("%d", &tstart);
			printf("Enter the end year  : ");
			scanf("%d", &tend);

			r = R / 100;

			printf("\nYear\t Principal\t Interest rate\t Compound ratio\t  Banlance\n");
			for (t = tstart; t <= tend; t++)  //Using for-loop to print the report from the start year up to the end year.
			{
				B = P * pow(1 + (r / n), (double)n * t);
				printf(" %d\t  %.2lf\t     %.3lf\t\t%d\t  %.2lf\n\n", t, P, r, n, B);
			}
		}



		else if (strcmp(option, "7") == 0)
		{
			x = 1;
			printf("Enter annual interest rate for both account (in %%): ");
			scanf("%lf", &R);

			printf("\n**ACCOUNT 1**\n");
			printf("Principal, P (in RM)   : ");
			scanf("%lf", &P);
			printf("Compound ratio, n      : ");
			scanf("%d", &n);
			printf("Duration, t (in years) : ");
			scanf("%d", &t);
			r = R / 100;
			B = P * pow(1 + (r / n), (double)n * t);
			printf("The balance of Account 1 after %dyears is RM%.2lf\n", t, B);

			//Declaring variables for account 2
			double P2;
			int n2;
			printf("\n**ACCOUNT 2**\n");
			printf("Principal, P (in RM)  : ");
			scanf("%lf", &P2);
			printf("Compound ratio, n     : ");
			scanf("%d", &n2);

			t2 = (log(B / P2)) / ((double)n2 * (log(1 + (r / (double)n2))));  //Finding how long account 2 takes.
			years = (int)floor(t2);                                           //Finding exact years by eliminating the decimals
			months = (int)ceil((t2 - (double)years) * 12.0);                  //Use years decimals to find months
			//printf("check, t2=%.3lf\n",t2);
			printf("*************************************************************************************************\n");
			if (months == 12)      //Because sometimes the answer may round up to 12
			{
				printf("Account 2 will take %dyear(s) to reach the balance of RM%.2lf in Account 1\n", years + 1, B);
			}
			else if (years == 0)   //In case it took less than a year, but the posibility is very low.
			{
				printf("Account 2 will take %dmonth(s) to reach the balance of RM%.2lf in Account 1\n", months, B);
			}
			else
			{
				printf("Account 2 will take %dyear(s) and %dmonth(s) to reach the balance of RM%.2lf in Account 1\n", years, months, B);
			}
			printf("*************************************************************************************************\n");
		}


		else
		{
			printf("ERROR. PLEASE KEY IN A VALID OPTION.");
		}

	} while (x == 0);

	return 0;
}