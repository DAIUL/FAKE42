#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void 	announce();
	void	SetName(std::string name);
};
	
Zombie* zombieHorde(int N, std::string name);

#endif