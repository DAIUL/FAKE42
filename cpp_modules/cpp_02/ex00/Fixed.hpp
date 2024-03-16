#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:

	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(Fixed const & fix);
	~Fixed();

	Fixed&	operator=(Fixed const & src);
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
};

#endif