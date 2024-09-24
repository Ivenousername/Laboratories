#pragma once
class Array
{
public:
	Array(int size = 10);
	Array(const Array& other);
	~Array();
	int &operator[](int index);
	const int &operator[](int index) const;

private:
	int* m_array = nullptr;
	int m_size = 0;
};