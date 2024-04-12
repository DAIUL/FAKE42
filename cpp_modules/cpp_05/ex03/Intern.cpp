#include "Intern.hpp"

Intern::Intern() {
	_forms[0] = "Robotomy Form";
	_forms[1] = "Shrubbery Form";
	_forms[2] = "Presidential Form";
}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern::~Intern() {
}

AForm*	Intern::makeForm(std::string formName, std::string targetName)
{
	int	i;

	for (i = 0; i < 3; i++)
		if (formName == _forms[i])
			break;

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(targetName));
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(targetName));
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(targetName));
		case 3:
			std::cout << formName << " isn't an available form..." << std::endl;
			break;
	}
	return (NULL);
}

Intern&	Intern::operator=(Intern const & src) {
	(void)src;
	return *this;
}