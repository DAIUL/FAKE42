#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	unsigned int	_size;
	T				*_array;
public:

	Array() : _array(new T[0]){};
	Array(unsigned int n) : _size(n), _array(new T[n]) {};
	Array(Array const & src) : _array(NULL) {*this = src;};
	~Array() {delete[] _array;};

	unsigned int	size(){
		unsigned int i;

		for (i = 0; _array; i++)

		return i;
	};

	Array&	operator=(Array const & src){
		if (this != &src)
		{
			_size = src._size;
			if (_array)
				delete[] _array;
			_array = new T[_size];
			for (unsigned int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		}
		return *this;
	};

	T&	operator[](unsigned int i){
		try {
			if (i < _size)
				return _array[i];	
			throw OutofBounds();
		}
		catch (std::exception& e) {
			std::cerr << e.what();
			static T default_value = T();
        	return default_value;
		}
	};

	class OutofBounds : public std::exception {
	public :
		virtual const char *what() const throw() {
					return "Error: Out of bounds";
				}
	};
	
};

#endif