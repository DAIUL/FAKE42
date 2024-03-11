#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie *horde = new Zombie[5];
	for (int i; i < n; i++)
		horde[i].SetName(name);
	return (horde);
}
