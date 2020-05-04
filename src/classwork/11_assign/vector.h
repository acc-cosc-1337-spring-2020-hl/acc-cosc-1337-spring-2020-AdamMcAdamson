//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v);//copy constructor-RULE OF 3 - c++98
	Vector& operator=(const Vector& v);//copy assignment-RULE OF 3 -c++98
	Vector(Vector&& v); //move constructor - RULE OF 5 C++ 11
	Vector& operator=(Vector&& v);//move assignment - RULE OF 5 C++11
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	void Resize(size_t new_size);
	void Push_Back(int value);
	~Vector();//destructor-RULE OF 3
private:
	/*
	Tracks space ready to use
	*/
	size_t size;
	/*
	Track reserved space
	*/
	size_t space{ 0 };
	/*
	Initial reserve default size
	*/
	const int RESERVE_DEFAULT_SIZE{ 8 };
	/*
	Size multiplier
	*/
	const int RESERVE_SIZE_MULTIPLIER{ 2 };

	int* nums;
};

#endif

void use_vector();
Vector get_vector();

