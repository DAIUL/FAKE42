#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, unsigned int len, void (*fct)(T&))
{
	for (unsigned int i = 0; i < len; i++)
		fct(array[i]);
}

#endif