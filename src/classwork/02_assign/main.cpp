//Write the include statement for decision.h here
#include "decision.h"
//Write include for capturing input from keyboard and displaying output to screen
#include <iostream>
#include <iomanip>

//Write namespace using statements for cout and cin
using std::cin; using std::cout;
using std::setprecision;

int main() 
{
	//create a double variable named hours
	double hours;
	//create a double variable named hourly_rate
	double hourly_rate;
	//Prompt user for keyboard input for hours and hourly_rate
	//save the input to variables hours and hourly_rate
	cout << "Input the employee's hours worked: ";
	cin >> hours;

	cout << "Input the employee's hourly rate: ";
	cin >> hourly_rate;

	//Create a double variable named gross_salary
	double gross_salary;

	//Call the gross_pay function and save its return value to the gross_salary variable
	gross_salary = gross_pay(hours, hourly_rate);

	//Display the gross_salary variable as follows:
	//Example ---->>>     Gross pay: 150.00   

	cout << "Gross pay: $" << gross_salary;

	return 0;
}

