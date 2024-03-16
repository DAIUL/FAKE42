#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fix) {
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

Fixed&	Fixed::operator=(Fixed const & fix)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fix)
		_value = fix.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed&	Fixed::min(Fixed& fix, Fixed& fix2) {
	if (fix.getRawBits() > fix2.getRawBits())
		return fix2;
	return fix;
}

Fixed const &	Fixed::min(Fixed const & fix, Fixed const & fix2) {
	if (fix.getRawBits() > fix2.getRawBits())
		return fix2;
	return fix;
}

Fixed&	Fixed::max(Fixed& fix, Fixed& fix2) {
	if (fix.getRawBits() > fix2.getRawBits())
		return fix;
	return fix2;
}

Fixed const &	Fixed::max(Fixed const & fix, Fixed const & fix2) {
	if (fix.getRawBits() > fix2.getRawBits())
		return fix;
	return fix2;
}