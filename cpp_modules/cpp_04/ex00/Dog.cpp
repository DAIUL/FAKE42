#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "New Dog created !" << std::endl;
}

Dog::Dog(Dog const & src) : Animal()
{
	*this = src;
	std::cout << "New Dog copied !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed !" << std::endl;
}

Dog&	Dog::operator=(Dog const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wan Wan !" << std::endl;
}