#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_HP = 100;
	_EP = 50;
	_AtkDmg = 20;
	std::cout << "ScavTrap was created !" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_HP = 100;
	_EP = 50;
	_AtkDmg = 20;
	std::cout << "ScavTrap " << _name << " was created !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "ScavTrap " << _name << " was copied !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed !" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & src)
{
	if (this != &src)
	{
		_name = src.GetValueStr("_name");
		_HP = src.GetValueInt("_HP");
		_EP = src.GetValueInt("_EP");
		_AtkDmg = src.GetValueInt("_AtkDmg");
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (_EP <= 0 || _HP <= 0)
	{
		if (_EP <= 0)
			std::cout << "ScavTrap " << _name << " have not enough Energy to attack..." << std::endl;
		else if (_HP <= 0)
			std::cout << "ScavTrap " << _name << " is already dead..." << std::endl;
		return ;
	}
	_EP--;
	std::cout << "ScavTrap " << _name << " has inflicted " << _AtkDmg << " damages to " << target << " !!" << std::endl;
}

void		ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode !" << std::endl;
}