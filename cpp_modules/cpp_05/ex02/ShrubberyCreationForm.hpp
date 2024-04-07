#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const & executor) const;

	std::string	getTarget();

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & src);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif