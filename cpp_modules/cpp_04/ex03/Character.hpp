#ifndef CHARACTER_H
# define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
private:
	AMateria*	_inventory [4];
	std::string	_name;
public:
	Character();
	Character(Character const & src);
	Character(std::string name);
	~Character();

	Character&	operator=(Character const & src);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria* const &	getInventory(int i) const;
};

#endif