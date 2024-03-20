#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "New WrongCat created !" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal()
{
	*this = src;
	std::cout << "New WrongCat copied !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed !" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Nya Nya ! (Mais avec une voix de vieux monsieur qui imite un chat)" << std::endl;
}