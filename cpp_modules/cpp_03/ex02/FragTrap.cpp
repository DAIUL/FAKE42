#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_HP = 100;
	_EP = 100;
	_AtkDmg = 30;
	std::cout << "FragTrap was created !" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_HP = 100;
	_EP = 100;
	_AtkDmg = 30;
	std::cout << "FragTrap " << _name << " was created !" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "FragTrap " << _name << " was copied !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed !" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & src)
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

void		FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " wants a high fives !" << std::endl;
}