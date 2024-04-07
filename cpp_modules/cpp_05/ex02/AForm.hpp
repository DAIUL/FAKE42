#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	_name;
	bool				_sign;
	unsigned int const	_gradeSign;
	unsigned int const	_gradeExec;
	AForm();
public:
	AForm(AForm const & src);
	AForm(std::string const name, unsigned int const gradeSign, unsigned int const gradeExec);
	virtual ~AForm();

	void	beSigned(Bureaucrat const & b);
	virtual void execute(Bureaucrat const & executor) const = 0;

	std::string const	getName() const;
	unsigned int		getGradeSign() const;
	unsigned int		getGradeExec() const;
	bool				getSign() const;

	AForm&	operator=(AForm const & src);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
}

std::ostream&	operator<<(std::ostream & out, AForm const & src);

#endif