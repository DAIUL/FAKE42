#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>
# include <iostream>

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const & src);
	~Serializer();
	
public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer&	operator=(Serializer const & src);

};

#endif