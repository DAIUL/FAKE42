#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45) {
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try {
		if ((executor.getGrade() > this->getGradeExec()) || (executor.getGrade() < 1))
		{
			executor.executeForm(*this);
			throw RobotomyRequestForm::GradeTooLowException();
		}
		else if (this->getSign() == false)
		{
			executor.executeForm(*this);
			throw RobotomyRequestForm::NotSignedException();
		}
		else
		{
			srand(time(NULL));
			int	random = rand() % 2;
			
			std::cout << "*Drilling noises...*" << std::endl;
		
			if (random == 0)
				std::cout << this->_target << " has been robotomized successfully !" << std::endl;
			else
				std::cout << this->_target << "'s robotomization failed " << std::endl;
			executor.executeForm(*this);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "RobotomyRequestForm : grade is too high ! Try a grade between 1 and 150\n";
}	

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "RobotomyRequestForm : grade is too low ! Try a grade between 1 and 150\n";
}

const char* RobotomyRequestForm::NotSignedException::what() const throw()
{
	return "RobotomyRequestForm : Can't be executed if not signed\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	if (this != &src)
	{
		_target = src.getTarget();
	}
	return *this;
}