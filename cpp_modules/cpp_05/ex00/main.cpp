#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 3);
	Bureaucrat	SergiSergio(Serge);
	Bureaucrat	Guy("Guy", 160);
	Bureaucrat	Rene("Rene", 0);

	Serge.upGrade();
	Serge.downGrade();
	std::cout << Serge << std::endl;
	Serge.upGrade();
	Serge.upGrade();
	std::cout << Serge << std::endl;
	Serge.upGrade();
	std::cout << Serge << std::endl;
	Guy.upGrade();
	SergiSergio.upGrade();

	std::cout << SergiSergio.getName() << std::endl;

	std::cout << Serge << std::endl;
	std::cout << SergiSergio << std::endl;
	std::cout << Guy << std::endl;

	return 0;
}