#include "vars.h"
#include <string>

using std::string;

int main() 
{
	string name = "John";
	
	display_number(10);
	display_number(20);
	
	int num = 5;

	display_number(num);
	display_number(square_number(num));

	int num1 = square_number(5);

	return 0;
}