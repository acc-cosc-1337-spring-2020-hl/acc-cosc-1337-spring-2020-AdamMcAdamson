#include "dna.h"


/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string & str)
{
	if (str.length() < 1) {
		return -1;
	}

	double count = 0;
	for (auto s : str)
	{
		if (s == 'G' || s == 'C') {
			count++;
		}
	}
	return count/str.length();
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string str)
{
	char temp;
	for (int i = 0; i < str.length() / 2; ++i) {
		temp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = temp;
	}

	return str;
}



/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string str)
{
	string reverse = get_reverse_string(str);
	for (int i = 0; i < reverse.length(); ++i) {
		if (reverse[i] == 'A') {
			reverse[i] = 'T';
		}
		else if (reverse[i] == 'T') {
			reverse[i] = 'A';
		}
		else if (reverse[i] == 'C') {
			reverse[i] = 'G';
		}
		else if (reverse[i] == 'G') {
			reverse[i] = 'C';
		}
	}

	return reverse;

}
