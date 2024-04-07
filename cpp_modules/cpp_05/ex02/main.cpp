#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 3);
	ShrubberyCreationForm	Shrubbery("Champs");

	Serge.executeForm(Shrubbery);
	Serge.signForm(Shrubbery);
	Serge.executeForm(Shrubbery);

	std::cout << Serge << std::endl;
	std::cout << Shrubbery << std::endl;

	return 0;
}