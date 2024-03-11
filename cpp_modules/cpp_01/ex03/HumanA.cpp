#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weaponA(weapon){
}

HumanA::~HumanA(){
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weaponA.getType() << std::endl;
}