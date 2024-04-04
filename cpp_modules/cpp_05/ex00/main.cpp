#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 5);
	Bureaucrat	Guy("Guy", 160);
	Bureaucrat	Rene("Rene", 0);

	Serge.upGrade(6);
	Serge.upGrade(2);
	Serge.downGrade(160);
	Serge.upGrade(70);

	std::cout << Serge << std::endl;
	std::cout << Guy << std::endl;

	return 0;
}