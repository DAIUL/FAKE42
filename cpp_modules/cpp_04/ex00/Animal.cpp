#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "New Animal created !" << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "New Animal copied !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed !" << std::endl;
}

Animal&	Animal::operator=(Animal const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
	}
	return *this;
}

std::string	Animal::GetValueStr(std::string value) const
{
	if (value == "type")
		return type;
	return 0;
}

void	Animal::makeSound() const
{
	std::cout << "ROAAAR" << std::endl;
}