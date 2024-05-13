#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const & src) {*this = src;}
RPN::~RPN() {}

RPN&	RPN::operator=(RPN const & src)
{
	if (this != &src)
	{
		_stack = src._stack;
	}
	return *this;
}

bool	RPN::checkExpr(char *expr)
{
	for (int i = 0; expr[i]; i++)
	{
		if (!isdigit(expr[i]) && !isOperat(expr[i]) && expr[i] != ' ') {
			std::cout << "Error" << std::endl;
			return false;
		}
		else if (isdigit(expr[i]) && isdigit(expr[i + 1])) {
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	return true;
}

void	RPN::resolve(char *expr)
{
	for (int i = 0; expr[i]; i++) {
		if (isdigit(expr[i]))
			_stack.push(atoi(&expr[i]));
		else if (isOperat(expr[i])) {
			if (_stack.size() < 2) {
				std::cout << "Error" << std::endl;
				return ;
			}
			int a;
			int b;
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();

			switch (isOperat(expr[i])) {
				case 1:
					_stack.push(a + b);
					break;
				case 2:
					_stack.push(a - b);
					break;
				case 3:
					_stack.push(a * b);
					break;
				case 4:
					_stack.push(a / b);
					break;
			}
		}
	}
	std::cout << _stack.top() << std::endl;
}

int	RPN::isOperat(char c)
{
	if (c == '+')
		return 1;
	else if (c == '-')
		return 2;
	else if (c == '*')
		return 3;
	else if (c == '/')
		return 4;
	else
		return 0;
}