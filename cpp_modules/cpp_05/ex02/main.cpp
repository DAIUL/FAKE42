#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 3);
	Bureaucrat	Guy("Guy", 10);
	Bureaucrat	Rene("Rene", 149);

	ShrubberyCreationForm	Shrubbery("Champs");
	RobotomyRequestForm		Robotomy("Kim des anges");
	PresidentialPardonForm	Presidential("Jospeh Staline");

	Shrubbery.execute(Serge);
	Shrubbery.beSigned(Serge);
	Shrubbery.execute(Serge);
	
	Robotomy.beSigned(Rene);
	Robotomy.beSigned(Guy);
	Robotomy.execute(Guy);
	
	Presidential.beSigned(Guy);
	Presidential.execute(Guy);
	Presidential.execute(Serge);

	std::cout << Serge << std::endl;
	std::cout << Guy << std::endl;
	std::cout << Rene << std::endl;
	std::cout << Shrubbery << std::endl;
	std::cout << Robotomy << std::endl;
	std::cout << Presidential << std::endl;

	return 0;
}