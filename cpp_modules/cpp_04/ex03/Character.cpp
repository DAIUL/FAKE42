#include "Character.hpp"

Character::Character()
{
	std::cout << "New Character created !" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	_name = name;
	std::cout << "New Character " << _name << " created !" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
	std::cout << "New Character copied !" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destroyed !" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character&	Character::operator=(Character const & src)
{
	if (this != &src)
	{
		_name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = src.getInventory(i)->clone();
		}
	}
	return *this;
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] && (_inventory[idx]->getType() == "ice" || _inventory[idx]->getType() == "cure"))
		_inventory[idx]->use(target);
}

AMateria* const &	Character::getInventory(int i) const
{
	return _inventory[i];
}

std::string const &	Character::getName() const
{
	return _name;
}

void  Character::equip(AMateria* m)
{
	int i;
	
	for (i = 0; _inventory[i] && i < 3; i++);
	if (!_inventory[i])
		_inventory[i] = m;
	else
		delete m;
}

void	Character::unequip(int idx)
{
	if (_inventory[idx])
		_inventory[idx] = NULL;
}