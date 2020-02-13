//write includes statements
#include "loops.h"
#include <iostream>
//write using statements for cin and cout

using std::cout;
using std::cin;


/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int choice = 1;
	int inputNum = 0;
	do {
		cout << "Enter a number: ";
		cin >> inputNum;

		cout << "\nThe factorial of " << inputNum << " is: " << factorial(inputNum);

		cout << "\nContinue...?(1: Yes, 0: No)";
		cin >> choice;
	} while (choice == 1);

	return 0;
}