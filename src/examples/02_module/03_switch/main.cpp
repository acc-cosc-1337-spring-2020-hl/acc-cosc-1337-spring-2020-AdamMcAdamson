#include<iostream>
#include "switch.h"

using std::cin;using std::cout;

int main() 
{
	int option;
	
//	cout << "Select your Option:\n  1 - Option 1\n  2 - Option 2\n  3 - Option 3\n  4 - Option 4\n";
	cout << "Enter a number(1-4)";
	cin >> option;

	string result = menu(option);

	cout << result;

	return 0;
}