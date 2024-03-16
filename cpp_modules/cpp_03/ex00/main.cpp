#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	BlaBla("BlaBla");
	ClapTrap	Truc("Truc");

	BlaBla.attack("Enfant en bas age");
	Truc.takeDamage(5);
	Truc.beRepaired(3);
	BlaBla.takeDamage(12);
	BlaBla.attack("OuiOui");
	std::cout << BlaBla.GetValueStr("_name") << " HP :" << BlaBla.GetValueInt("_HP") << " / EP :" << BlaBla.GetValueInt("_EP") << std::endl;
	std::cout << Truc.GetValueStr("_name") << " HP :" << Truc.GetValueInt("_HP") << " / EP :" << Truc.GetValueInt("_EP") << std::endl;
	return 0;
}