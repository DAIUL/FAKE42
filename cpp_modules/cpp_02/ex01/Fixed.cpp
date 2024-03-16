#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fix) : _value(0){
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int	nb) : _value(nb << _bits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float	nb) : _value(roundf(nb * (1 << _bits))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int 	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void 	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float 	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}

int 	Fixed::toInt(void) const
{
	return (_value >> _bits);
}

std::ostream&	operator<<(std::ostream& out, Fixed const & fix)
{
	out << fix.toFloat();
	return out;
}

Fixed&	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		_value = src.getRawBits();
	return *this;
}