#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "New Cure created !" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
	*this = src;
	std::cout << "New Cure copied !" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destroyed !" << std::endl;
}

Cure&	Cure::operator=(Cure const & src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* 	Cure::clone() const
{
	return new Cure();
}