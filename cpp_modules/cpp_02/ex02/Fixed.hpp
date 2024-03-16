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

	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;

	Fixed&	operator=(Fixed const & src);
	bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

	static Fixed&			min(Fixed& fix, Fixed& fix2);
	static Fixed const &	min(Fixed const & fix, Fixed const & fix2);
	static Fixed&			max(Fixed& fix, Fixed& fix2);
	static Fixed const &	max(Fixed const & fix, Fixed const & fix2);
};

std::ostream&	operator<<(std::ostream& out, Fixed const & fix);

#endif