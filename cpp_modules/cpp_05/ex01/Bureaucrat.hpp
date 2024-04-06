#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	unsigned int		_grade; 
	Bureaucrat();
public:
	Bureaucrat(std::string const name, unsigned int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();

	void 		upGrade();
	void 		downGrade();
	void		signForm(Form const &) const;
	
	std::string const 	getName() const;
	unsigned int 		getGrade() const;
	
	Bureaucrat&	operator=(Bureaucrat const & src);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b);

#endif