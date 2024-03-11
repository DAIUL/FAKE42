#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::Zombie(){
}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed !" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
