#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "New Ice created !" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
	*this = src;
	std::cout << "New Ice copied !" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destroyed !" << std::endl;
}

Ice&	Ice::operator=(Ice const & src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* 	Ice::clone() const
{
	return new Ice();
}