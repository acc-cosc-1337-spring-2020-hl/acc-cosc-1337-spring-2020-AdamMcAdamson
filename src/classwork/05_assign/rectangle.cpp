//Write include statement
#include "rectangle.h"

/*
Write the class function code for the Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/

int rectangle::calculate_area()
{
	return width * height;
}

int rectangle::get_area()
{
	return area;
}

std::ostream & operator<<(std::ostream & out, const rectangle & rect)
{
	out << "The area is: " << rect.area;
	return out;
}
