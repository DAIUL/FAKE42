#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){
}

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

std::string const&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}