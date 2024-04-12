#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const & executor) const;

	std::string	getTarget() const;

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & src);

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