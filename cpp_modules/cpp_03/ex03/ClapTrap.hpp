#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
protected:

	std::string	_name;
	int			_HP;
	int			_EP;
	int			_AtkDmg;

	ClapTrap();
	
public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	virtual ~ClapTrap();

	ClapTrap&			operator=(ClapTrap const & src);
	int					GetValueInt(std::string value) const;
	std::string			GetValueStr(std::string value) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif