#ifndef WEAPON_H
#define	 WEAPON_H

#include <string.h>
#include <string>
#include <iostream>
#include <ostream>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(std::string type);
	Weapon();
	~Weapon();

	std::string const&	getType() const;
	void				setType(std::string new_type);
};

#endif