#ifndef FRAGTRAP_H
# define FRAGTRAP_H


#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	
	FragTrap();

public:

	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap();

	FragTrap&	operator=(FragTrap const & src);
	
	void		highFivesGuys();

};

#endif