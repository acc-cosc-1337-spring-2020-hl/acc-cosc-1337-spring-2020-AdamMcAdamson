//
/* 

-- Having issues with Travis CI and size_t, commented temporarily


#ifndef MY_VECTOR_H
#define MY VECTOR_H

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector &v);
	size_t Size()const { return size; }
	void set_size(size_t s) { size = s; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i) const { return nums[i]; }
	~Vector(); //destructor;
private:
	size_t size;
	int* nums;
};

void use_vector();
#endif //!MY_VECTOR_H

*/
