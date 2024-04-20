#include "Array.hpp"

int	main()
{
	Array<int>	intTab(5);
	Array<std::string>	strTab(5);

	intTab[0] = 1;
	intTab[1] = 2;
	intTab[2] = 3;
	intTab[3] = 4;

	strTab[0] = "JDON";
	strTab[1] = "MY";
	strTab[2] = "SOUL";
	strTab[3] = "!";

	std::cout << intTab[2] << std::endl;
	std::cout << strTab[13] << std::endl;
	std::cout << strTab[0] << std::endl;
	std::cout << strTab[1] << std::endl;
	std::cout << strTab[2] << std::endl;
	std::cout << strTab[3] << std::endl;

	return 0;
}