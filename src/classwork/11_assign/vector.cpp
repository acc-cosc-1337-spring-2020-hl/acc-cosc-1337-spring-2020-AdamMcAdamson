/*

-- Having issues with Travis CI and size_t, commented temporarily



#include "vector.h"
#include  <iostream>
Vector::Vector(size_t sz)
	:size{ sz }, nums{new int[sz]}
{
	for (size_t i = 0; i < sz; i++)
	{
		nums[i] = 0;
	}
}

Vector::Vector(const Vector & v)
	:size{ v.Size() }, nums{new int[v.Size()]}
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		nums[i] = v[i];
	}
}

Vector::~Vector()
{
	std::cout << "release memory";
	delete[] nums;
}

void use_vector()
{
	Vector v(3);
}

*/