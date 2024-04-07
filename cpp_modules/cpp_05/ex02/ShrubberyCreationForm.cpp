#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try {
		if ((executor.getGrade() > _gradeExec) || (executor.getGrade() < 1))
		{
			executor.executeForm(*this);
			throw ShrubberyCreationForm::GradeTooLowException();
		}
		else if (_sign == false)
		{
			executor.executeForm(*this);
			throw ShrubberyCreationForm::NotSignedException();
		}
		else
		{
			std::ofstream	dest;

			dest.open(_target + "_shrubbery");
			if (dest.is_open())
			{
				dest << "         &&& &&  & && " << std::endl;
				dest << "		&& &\/&\|& ()|/ @, && " << std::endl;
				dest << "		&\/(/&/&||/& /_/)_&/_& " << std::endl;
				dest << "	&() &\/&|()|/&\/ % & () " << std::endl;
				dest << "	&_\_&&_\ |& |&&/&__%_/_& && " << std::endl;
				dest << "	&&   && & &| &| /& & % ()& /&& " << std::endl;
				dest << "	()&_---()&\&\|&&-&&--%---()~ " << std::endl;
				dest << "		&&     \||| " << std::endl;
				dest << "				||| " << std::endl;
				dest << "				||| " << std::endl;
				dest << "				||| " << std::endl;
				dest << "		, -=-~  .-^- _ " << std::endl;
				executor.executeForm(*this);
			}
			else
				std::cerr << "can't open file" << std::endl;
			dest.close();
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::string	ShrubberyCreationForm::getTarget() {
	return _target;
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "ShrubberyCreationForm : grade is too high ! Try a grade between 1 and 150\n";
}	

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "ShrubberyCreationForm : grade is too low ! Try a grade between 1 and 150\n";
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return "ShrubberyCreationForm : Can't be executed if not signed\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if (this != &src)
	{
		_target = src.getTarget();
	}
	return *this;
}