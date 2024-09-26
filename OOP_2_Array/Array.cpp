#include "Array.h"


Array::Array(int size)
{
	if (size < 0)
	{
		size = -size;
	}
	m_size = size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}

Array::~Array()
{
	delete[] m_array;
}

Array::Array(const Array& other)
{
	m_size = other.m_size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

int &Array::operator[](int index) {
	return m_array[index];
}
const int &Array::operator[](int index) const {
	return m_array[index];
}