//write include statements
#include "if_else.h"
#include<iostream>

//write cin and cout using statements
using std::cout;
using std::cin;

/*
Write code to capture year from keyboard.
Pass the year to get_generation function and display function result.
*/
int main() 
{
	int year;

	cout << "Enter a Year (1925-2014): ";
	cin >> year;
	
	cout << "The generation for " << year << " was: " << get_generation(year);
	
	return 0;
}