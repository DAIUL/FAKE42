#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;

	std::string	getTarget() const;

	RobotomyRequestForm&	operator=(RobotomyRequestForm const & src);

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