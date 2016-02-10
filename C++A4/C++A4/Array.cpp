
// Array class implementation.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility> // contains std::move
#include "Array.h" // Array class definition

using namespace std;

// default constructor for class Array (default size 10)
template<typename T>
Array<T>::Array(size_t arraySize) : size(arraySize), ptr(new T[size])
{
	cout << "Array(int) constructor called" << endl;

	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = 0; // set pointer-based array element
	}
} // end Array default constructor


  // copy constructor for class Array;	// must receive a reference to an Array
template<typename T>
Array<T>::Array(const Array &arrayToCopy): size(arrayToCopy.size), ptr(new T[size])
{
	cout << "Array copy constructor called" << endl;

	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}
} // end Array copy constructor

template<typename T>
Array<T>::Array(Array &&arrayToMove)noexcept : size( arrayToMove.size),ptr( arrayToMove.ptr)
{
	cout << "Array to move constructor called" << endl;

	arrayToMove.size = 0;
	arrayToMove.ptr = nullptr;
}


  // destructor for class Array
template<typename T>
Array<T>::~Array()
{
	cout << "Array destructor called" << endl;
	delete[] ptr; // release pointer-based array space
} // end destructor

  // return number of elements of Array
template<typename T>
size_t Array<T>::getSize() const
{
	return size; // number of elements in Array
} // end function getSize

  // copy assignment operator
template<typename T>
Array<T> &Array::operator=(const Array &right)
{
	cout << "Array copy assignment operator called" << endl;

	if (&right != this) // avoid self-assignment
	{
		// for Arrays of different sizes, deallocate original
		// left-side Array, then allocate new left-side Array
		if (size != right.size)
		{
			delete[] ptr; // release space
			size = right.size; // resize this object
			T ptr = new int[size]; // create space for Array copy
		} // end inner if



		for (size_t i = 0; i < size; ++i)
			ptr[i] = right.ptr[i]; // copy array into object
	} // end outer if

	return *this; // enables x = y = z, for example
} // end copy assignment operator=

template<typename T>
Array<T> &Array::operator=(Array &&arrayToMove)noexcept
{
	cout << "Array move assignment operator called";

	if (&arrayToMove != this)
	{
		delete[] ptr;
		size = arrayToMove.size;
		ptr = arrayToMove.ptr;

		arrayToMove.size = 0;
		arrayToMove.ptr = nullptr;
	}

	return *this;
}


  // determine if two Arrays are equal and
  // return true, otherwise return false
template<typename T>
bool Array<T>::operator==(const Array &right) const
{
	if (size != right.size)
	{
		return false; // arrays of different number of elements
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ptr[i] != right.ptr[i])
		{
			return false; // Array contents are not equal
		}
	}
	return true; // Arrays are equal
} // end function operator==

  // overloaded subscript operator for non-const Arrays;
  // reference return creates a modifiable lvalue
template<typename T>
T &Array::operator[](size_t subscript)
{
	// check for subscript out-of-range error
	if (subscript >= size)
	{
		throw out_of_range("Subscript out of range");
	}
	return ptr[subscript]; // reference return
} // end function operator[]





  // overloaded subscript operator for const Arrays
  // const reference return creates an rvalue
template<typename T>
T Array::operator[](size_t subscript) const
{
	// check for subscript out-of-range error
	if (subscript >= size)
		throw out_of_range("Subscript out of range");

	return ptr[subscript]; // returns copy of this element
} // end function operator[]

  // overloaded input operator for class Array;
  // inputs values for entire Array
template<typename T>
istream &operator>>(istream &input, Array &a)
{
	for (size_t i = 0; i < a.size; ++i)
	{
		input >> a.ptr[i];
	}
	return input; // enables cin >> x >> y;
} // end function

  // overloaded output operator for class Array
template<typename T>
ostream &operator<<(ostream &output, const Array &a)
{
	// output private ptr-based array
	for (size_t i = 0; i < a.size; ++i)
	{
		output << a.ptr[i] << " ";
	}
	output << endl;
	return output; // enables cout << x << y;
} // end function operator<<

