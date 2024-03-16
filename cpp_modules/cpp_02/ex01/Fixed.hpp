#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(Fixed const & fix);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();

	Fixed&	operator=(Fixed const & src);
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;

};

std::ostream&	operator<<(std::ostream& out, Fixed const & fix);

#endif