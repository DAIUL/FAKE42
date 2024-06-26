#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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

	Bureaucrat&	operator=(Bureaucrat const & src);
	void 		upGrade();
	void 		downGrade();
	
	std::string const 	getName() const;
	unsigned int 		getGrade() const;

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