#ifndef _TICKET_DATABASE_H_
#define _TICKET_DATABASE_H_
#include <iostream>

using namespace std;

template <typename T> 
class Ticket_Database
{
public:
	Ticket_Database()
	{
		// initialize
		m_size = 0;
		m_capacity = 4;
		arr = new T[4];
	}

	~Ticket_Database()
	{
		// delete arr id necessary
		delete[]arr;
	}

	int size()
	{
		// return the m_size
		return m_size;
	}

	int capacity()
	{
		// return the m_capacity
		return  m_capacity;
	}
	
	T at(int index)
	{
		// return the element at [index]
		if (index < m_size){
			return *(arr + index);
		}
		T a = NULL;
		return a;
	}

	T& operator[](int index)
	{
		// return the element at [index]
		if (index < m_size){
			return *(arr + index);
		}
		T a = NULL;
		return a;
	}

	void insert(T in, int position)
	{
		// insert the element at position
		T[position] = in;
	}

	void erase(int position)
	{
		// erase the element at position
		delete arr[position];
	}

	void reserve(int new_size)
	{
		// reserve new_size space for arr
		T *tmp = new T[new_size];
		for (int i = 0; i < m_size; i++){
			*(tmp + i) = *(arr + i);
		}
		arr = tmp;
	}

	void pop_back()
	{
		// remove the last element
		if (m_size != 0){
			m_size--;
		}
	}

	void push_back(T in)
	{
		// add a new element
		// if the size is not enough, m_capacity is increased by 4 in default
		if (m_size == m_capacity){
			m_capacity += 4;
			reserve(m_capacity);
		}
		*(arr + m_size) = in;
		m_size++;
	}

private:
	T* arr;
	int m_size;
	int m_capacity;
};

#endif