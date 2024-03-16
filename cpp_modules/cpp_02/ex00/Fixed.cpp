#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fix) : _value(0){
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
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

Fixed&	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		_value = src.getRawBits();
	return *this;
}