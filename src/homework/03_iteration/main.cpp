//write include statements
#include "dna.h"
#include <iostream>
//write using statements
using std::cout;
using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	string choice;
	string dna;
	string repeat;
	do 
	{
		cout << "Enter 1 to Get the GC Content or 2 to Get the DNA Complement: ";
		cin >> choice;

		if (choice != "1" && choice != "2") {
			continue;
		}

		cout << "\nEnter the DNA String: ";
		cin >> dna;

		if (choice == "1") {
			cout << "\nGC Content: " << get_gc_content(dna);
		}
		else if (choice == "2") {
			cout << "\nDNA Complement: " << get_dna_complement(dna);
		}

		cout << "\nContinue...? (Y: yes, N: no)";
		cin >> repeat;

	} while (repeat == "y" || repeat == "Y");
	
		
		
	return 0;
}