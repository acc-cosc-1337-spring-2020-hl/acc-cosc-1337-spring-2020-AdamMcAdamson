#include "decision.h"
//Write the function code that returns the product of hours and hourly_rate.

double gross_pay(double hours, double hourly_rate)
{
	double total = 0.0;
	
	if (hours > 40) {
		total = 40 * hourly_rate + ((hours-40)*hourly_rate*1.5);
	}
	else {
		total = hourly_rate * hours;
	}


	return total;
}
