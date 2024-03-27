#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "New Materia created !" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "New Materia created !" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	std::cout << "New Materia copied !" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Materia destroyed !" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const & src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "*AMateria do something useless to " << target.getName() << "*" << std::endl;
}