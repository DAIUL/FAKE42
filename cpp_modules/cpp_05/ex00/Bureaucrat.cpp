#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string const name, int	grade) : _name(name){
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
		else 
			_grade = grade;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Grade is too low !" << std::endl;
		std::cout << "Try un grade between 1 and 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Grade is too high !" << std::endl;
		std::cout << "Try a grade between 1 and 150" << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
}

void	Bureaucrat::upGrade(int upgrade){
	try {
		if ((_grade - upgrade) < 1)
			throw Bureaucrat::GradeTooLowException();
		else if ((_grade - upgrade) > 150)
			throw Bureaucrat::GradeTooHighException();
		else 
			_grade -= upgrade;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Grade is too low !" << std::endl;
		std::cout << "Try un grade between 1 and 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Grade is too high !" << std::endl;
		std::cout << "Try a grade between 1 and 150" << std::endl;
	}
}

void	Bureaucrat::downGrade(int upgrade){
	try {
		if ((_grade + upgrade) < 1)
			throw Bureaucrat::GradeTooLowException();
		else if ((_grade + upgrade) > 150)
			throw Bureaucrat::GradeTooHighException();
		else 
			_grade += upgrade;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Grade is too low !" << std::endl;
		std::cout << "Try un grade between 1 and 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Grade is too high !" << std::endl;
		std::cout << "Try a grade between 1 and 150" << std::endl;
	}
}

std::string const Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return out;
}