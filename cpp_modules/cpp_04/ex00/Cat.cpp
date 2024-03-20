#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "New Cat created !" << std::endl;
}

Cat::Cat(Cat const & src) : Animal()
{
	*this = src;
	std::cout << "New Cat copied !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed !" << std::endl;
}

Cat&	Cat::operator=(Cat const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Nya Nya !" << std::endl;
}