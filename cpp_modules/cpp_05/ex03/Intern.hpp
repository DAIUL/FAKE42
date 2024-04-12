#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
	std::string _forms[3];
public:
	Intern();
	Intern(Intern const & src);
	~Intern();

	AForm*	makeForm(std::string formName, std::string targetName);

	Intern&	operator=(Intern const & src);
};

#endif