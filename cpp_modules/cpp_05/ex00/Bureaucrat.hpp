#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade; 
	Bureaucrat();
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();

	Bureaucrat&	operator=(Bureaucrat const & src);
	void 		upGrade(int upgrade);
	void 		downGrade(int upgrade);
	
	std::string const 	getName() const;
	int 				getGrade() const;

	class GradeTooHighException : public std::exception
	{
	};

	class GradeTooLowException : public std::exception
	{
	};

};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b);

#endif