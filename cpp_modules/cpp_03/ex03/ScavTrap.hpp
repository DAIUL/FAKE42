#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

	class ScavTrap : virtual public ClapTrap
	{
	protected:
		
		ScavTrap();

	public:

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		ScavTrap&	operator=(ScavTrap const & src);

		void 		attack(const std::string& target);
		void		guardGate();

	};

#endif