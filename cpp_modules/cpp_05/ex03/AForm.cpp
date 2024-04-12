#include "AForm.hpp"

AForm::AForm() : _name("Mumei"), _gradeSign(150), _gradeExec(150) {
	_sign = false;
}

AForm::AForm(std::string const name, unsigned int	const gradeSign, unsigned int const gradeExec) 
: _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	try {
		if ((gradeSign < 1) || (gradeExec < 1))
			throw AForm::GradeTooHighException();
		else if ((gradeSign > 150) || (gradeExec > 150))
			throw AForm::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

AForm::AForm(AForm const & src) 
: _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec()) {
	*this = src;
}

AForm::~AForm() {
}

void	AForm::beSigned(Bureaucrat const & b)
{
	try {
		if ((b.getGrade() > _gradeSign) || (b.getGrade() < 1))
		{
			b.signForm(*this);
			throw AForm::GradeTooLowException();
		}
		else
		{
			_sign = true;
			b.signForm(*this);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::string const	AForm::getName() const {
	return _name;
}

unsigned int	AForm::getGradeSign() const {
	return _gradeSign;
}

unsigned int	AForm::getGradeExec() const {
	return _gradeExec;
}

bool	AForm::getSign() const {
	return _sign;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm : grade is too high ! Try a grade between 1 and 150\n";
}	

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm : grade is too low ! Try a grade between 1 and 150\n";
}

AForm&	AForm::operator=(AForm const & src)
{
	if (this != &src)
	{
		_sign = src.getSign();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream & out, AForm const & src)
{
	out << "Name : " << src.getName() << ", Sign : " << src.getSign() << ", GradeSign : " << src.getGradeSign() << ", GradeExec : " << src.getGradeExec();
	return out;
}