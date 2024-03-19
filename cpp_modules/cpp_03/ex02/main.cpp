#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	r1("La roue gauche de la daronne a Lucas");
	ScavTrap	r2("Enfant en bas age");
	FragTrap	r3("Handicape sous fentanyl");

	r3.takeDamage(101);
	r1.attack(r2.GetValueStr("_name"));
	r2.beRepaired(1);
	r2.beRepaired(1);
	r2.beRepaired(1);
	r2.beRepaired(1);
	r3.beRepaired(1);
	r3.beRepaired(1);
	r2.beRepaired(1);
	r2.beRepaired(1);
	r2.attack("BlaBla");

	std::cout << r1.GetValueStr("_name") << " HP :" << r1.GetValueInt("_HP") << " / EP :" << r1.GetValueInt("_EP") << std::endl;
	std::cout << r2.GetValueStr("_name") << " HP :" << r2.GetValueInt("_HP") << " / EP :" << r2.GetValueInt("_EP") << std::endl;
	std::cout << r3.GetValueStr("_name") << " HP :" << r3.GetValueInt("_HP") << " / EP :" << r3.GetValueInt("_EP") << std::endl;
	return 0;
}