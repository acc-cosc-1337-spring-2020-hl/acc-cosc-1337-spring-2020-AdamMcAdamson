#include <iostream>
#include <string>
#include "vectors.h"

using std::cout;
using std::cin;
using std::string;

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	string repeat;
	string choice;
	vector<int> example{ 8, 4, 20, 88, 66, 99 };
	vector<int> primes;
	int input;
	do
	{
		cout << "Enter 1 to Get the Max value of a Vector, 2 to Get Primes: ";
		cin >> choice;
		cout << "\n";
		if (choice != "1" && choice != "2") {
			repeat = "y";
			continue;
		}

		

		if (choice == "1") 
		{
			cout << "Max Value:\t" << get_max_from_vector(example);
		}
		else if (choice == "2")
		{
			cout << "Enter the max value: ";
			cin >> input;
			cout << "\nVector of Primes:\n";
			primes = vector_of_primes(input);
			for (auto num : primes) {
				cout << num << " ";
			};
		}

		cout << "\n\nContinue...? (Y: yes, N: no)";
		cin >> repeat;
		cout << "\n";
	} while (repeat == "y" || repeat == "Y");

	return 0;
}