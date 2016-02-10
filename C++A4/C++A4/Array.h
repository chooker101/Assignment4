#pragma once

#include <iostream>

template<typename T>
class Array
{
	friend std::ostream &operator<<(std::ostream &, const Array &);
	friend std::istream &operator>>(std::istream &, Array &);

public:
	Array(size_t = 10);
	Array(const Array &);
	Array(Array &&) noexcept;
	~Array();
	size_t getSize() const;

	Array &operator=(const Array &);
	Array &operator=(Array &&) noexcept;
	bool operator==(const Array &)const;

	bool operator!=(const Array &right)const
	{
		return !(*this == right);
	}

	int &operator[](size_t);

	int operator[](size_t)const;
private:
	size_t size;
	T * ptr;
};