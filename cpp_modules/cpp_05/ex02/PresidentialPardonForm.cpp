#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5) {
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try {
		if ((executor.getGrade() > this->getGradeExec()) || (executor.getGrade() < 1))
		{
			executor.executeForm(*this);
			throw PresidentialPardonForm::GradeTooLowException();
		}
		else if (this->getSign() == false)
		{
			executor.executeForm(*this);
			throw PresidentialPardonForm::NotSignedException();
		}
		else
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
			executor.executeForm(*this);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::string	PresidentialPardonForm::getTarget() const {
	return _target;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "PresidentialPardonForm : grade is too high ! Try a grade between 1 and 150\n";
}	

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "PresidentialPardonForm : grade is too low ! Try a grade between 1 and 150\n";
}

const char* PresidentialPardonForm::NotSignedException::what() const throw()
{
	return "PresidentialPardonForm : Can't be executed if not signed\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	if (this != &src)
	{
		_target = src.getTarget();
	}
	return *this;
}