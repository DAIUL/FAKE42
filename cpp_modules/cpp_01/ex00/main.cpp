#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zom = newZombie("Akira");
	randomChump("Kencho");

	delete zom;
	return (0);
}