#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int	grade) : _name(name), _grade(grade) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {
}

void	Bureaucrat::upGrade() {
	try {
		if ((_grade < 1) || (_grade - 1 < 1))
			throw Bureaucrat::GradeTooHighException();
		else if ((_grade > 150) || (_grade - 1 > 150))
			throw Bureaucrat::GradeTooLowException();
		else 
			_grade--;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

void	Bureaucrat::downGrade() {
	try {
		if ((_grade < 1) || (_grade + 1 < 1))
			throw Bureaucrat::GradeTooHighException();
		else if ((_grade > 150) || (_grade + 1 > 150))
			throw Bureaucrat::GradeTooLowException();
		else 
			_grade++;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

void	Bureaucrat::signForm(Form const & f) const
{
	if (f.getSign() == true)
		std::cout << _name << " signed " << f.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << f.getName() << " because their garde was too low..." << std::endl; 
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high ! Try a grade between 1 and 150\n";
}	

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low ! Try a grade between 1 and 150\n";
}

std::string const Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		_grade = src.getGrade();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}