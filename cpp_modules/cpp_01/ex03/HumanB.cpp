#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
}

HumanB::HumanB(){
}

HumanB::~HumanB(){
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weaponB = &weapon;
}