#include "Form.hpp"

Form::Form() {
}

Form::Form(std::string const name, unsigned int	const gradeSign, unsigned int const gardeExec) 
: _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(_gradeExec) {
	try {
		if ((gradeSign < 1) || (gardeExec < 1))
			throw Form::GradeTooHighException();
		else if ((gradeSign > 150) || (gardeExec > 150))
			throw Form::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

Form::Form(Form const & src) 
: _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec()) {
	*this = src;
}

Form::~Form() {
}

void	Form::beSigned(Bureaucrat const & b)
{
	try {
		if ((b.getGrade() > _gradeSign) || (b.getGrade() < 1))
			throw Form::GradeTooLowException();
		else
		{
			_sign = true;
			b.signForm(this);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::string const	Form::getName() const {
	return _name;
}

unsigned int const	Form::getGradeSign() const {
	return _gradeSign;
}

unsigned int const	Form::getGradeExec() const {
	return _gradeExec;
}

bool	Form::getSign() const {
	return _sign;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form : grade is too high !\nTry a grade between 1 and 150\n";
}	

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form : grade is too low !\nTry a grade between 1 and 150\n";
}

Form&	Form::operator=(Form const & src)
{
	if (this != &src)
	{
		_sign = src.getSign();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream & out, Form const & src)
{
	out << "Name : " << src.getName() << ", Sign : " << src.getSign() << ", GradeSign : " << src.getGradeSign() << ", GradeExec : " << src.getGradeExec();
	return out;
}