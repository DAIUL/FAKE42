#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const	_name;
	bool				_sign;
	unsigned int const	_gradeSign;
	unsigned int const	_gradeExec;
	Form();
public:
	Form(Form const & src);
	Form(std::string const name, unsigned int const gradeSign, unsigned int const gradeExec);
	~Form();

	void	beSigned(Bureaucrat const & b);

	std::string const	getName() const;
	unsigned int const	getGradeSign() const;
	unsigned int const	getGradeExec() const;
	bool				getSign() const;

	Form&	operator=(Form const & src);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream & out, Form const & src);

#endif