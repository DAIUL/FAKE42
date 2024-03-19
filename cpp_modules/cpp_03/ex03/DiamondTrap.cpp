#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_HP = FragTrap::_HP;
	_EP = ScavTrap::_EP;
	_AtkDmg = FragTrap::_AtkDmg;
	std::cout << "DiamondTrap was created !" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_Dname = name;
	ClapTrap::_name = name + "_clap_name";
	_HP = FragTrap::_HP;
	_EP = ScavTrap::_EP;
	_AtkDmg = FragTrap::_AtkDmg;
	std::cout << "DiamondTrap " << _name << " was created !" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap " << _name << " was copied !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroyed !" << std::endl;
}

std::string	DiamondTrap::GetValueStrD(std::string value) const
{
	if (value == "_Dname")
		return _Dname;
	return 0;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & src)
{
	if (this != &src)
	{
		_Dname = src.GetValueStr("_Dname");
		ClapTrap::_name = _Dname + "_clap_name";
		_HP = src.GetValueInt("_HP");
		_EP = src.GetValueInt("_EP");
		_AtkDmg = src.GetValueInt("_AtkDmg");
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Hey i'm " << _Dname << " but you can call me " << ClapTrap::_name << "!" << std::endl;
}