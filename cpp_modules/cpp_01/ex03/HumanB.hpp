#ifndef HUMANB_H
#define	 HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* 		_weaponB;
	std::string 	_name;
public:
	HumanB(std::string name);
	HumanB();
	~HumanB();

	void	attack();
	void	setWeapon(Weapon& weapon);
};

#endif