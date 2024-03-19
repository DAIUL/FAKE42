#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:

	std::string	_Dname;
	DiamondTrap();
	
public:

	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap();

	DiamondTrap&	operator=(DiamondTrap const & src);
	void			whoAmI();
	std::string		GetValueStrD(std::string value) const;

};

#endif