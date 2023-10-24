#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _elements;
		unsigned int _size;

	public:
		// Construction with no parameter: Creates an empty array.
		Array() : _elements(NULL), _size(0)
		{
			std::cout << "Default Array constructed" << std::endl;
		}

		// Construction with an unsigned int n as a parameter:
		// Creates an array of n elements initialized by default.
		Array(unsigned int n) : _size(n)
		{
			_elements = new T[n];
			for (unsigned int i = 0; i < n; i++)
				_elements[i] = T();
			std::cout << "Array with n parameter constructed" << std::endl;
		}

		// Destructor
		~Array()
		{
			std::cout << "Array destructed" << std::endl;
			delete[] _elements;
		}

		// Copy Constructor
		Array(const Array<T>& ref) : _elements(NULL), _size(0)
		{
			if (ref._size > 0)
			{
				_size = ref._size;
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = ref._elements[i];
				std::cout << "Array copied" << std::endl;
			}
		}

		// Assignment Operator=
		Array& operator=(const Array<T>& ref)
		{
			if (this != &ref)
			{
				delete[] _elements;
				if (ref._size > 0)
				{
					_size = ref._size;
					_elements = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_elements[i] = ref._elements[i];
					std::cout << "Array assigned" << std::endl;
				}
				else
				{
					_size = 0;
					_elements = NULL;
				}
			}
			return (*this);
		}

		// Subscript Operator[]
		T& operator[] (unsigned int index)
		{
			if (index < _size)
				return _elements[index];
			else
				throw std::out_of_range("Index out of range");
		}

		// Return size of the Array
		unsigned int	size() const
		{
			return _size;
		}
};