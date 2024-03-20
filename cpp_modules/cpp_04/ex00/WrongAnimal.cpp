#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "New WrongAnimal created !" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
	std::cout << "New WrongAnimal copied !" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed !" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
	}
	return *this;
}

std::string	WrongAnimal::GetValueStr(std::string value) const
{
	if (value == "type")
		return type;
	return 0;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "ROAAAR (Mais avec une voix de vieux monsieur qui imite un animal)" << std::endl;
}