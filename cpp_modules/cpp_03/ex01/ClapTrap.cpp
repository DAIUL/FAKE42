#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _HP(10), _EP(10), _AtkDmg(0) {
	std::cout << "New ClapTrap was created !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AtkDmg(0) {
	std::cout << _name << " was created !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << _name << " was copied !" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " was destroyed" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & src)
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

int	ClapTrap::GetValueInt(std::string value) const
{
	if (value == "_HP")
		return _HP;
	if (value == "_EP")
		return _EP;	
	if (value == "_AtkDmg")
		return _AtkDmg;
	return 0;
}

std::string	ClapTrap::GetValueStr(std::string value) const
{
	if (value == "_name")
		return _name;
	return 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (_EP <= 0 || _HP <= 0)
	{
		if (_EP <= 0)
			std::cout << _name << " have not enough Energy to attack..." << std::endl;
		else if (_HP <= 0)
			std::cout << _name << " is already dead..." << std::endl;
		return ;
	}
	_EP--;
	std::cout << _name << " has inflicted " << _AtkDmg << " damages to " << target << " !!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HP <= 0)
	{
		std::cout << _name << " is already dead..." << std::endl;
		return ;
	}
	_HP -= amount;
	std::cout << _name << " lost " << amount << "HP !" << std::endl;
	if (_HP > 0)
		std::cout << _name << " have " << _HP << " HP remaining !" << std::endl;
	else 
		std::cout << _name << " died from this attack..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EP <= 0 || _HP <= 0)
	{
		if (_EP <= 0)
			std::cout << _name << " have not enough Energy to repair himself..." << std::endl;
		else if (_HP <= 0)
			std::cout << _name << " is already dead..." << std::endl;
		return ;
	}
	_HP += amount;
	_EP--;
	std::cout << _name << " recovered " << amount << " HP !" << std::endl;
	std::cout << _name << " have now " << _HP << " HP !" << std::endl;
}