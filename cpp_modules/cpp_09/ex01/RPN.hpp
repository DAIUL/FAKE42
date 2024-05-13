#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

class RPN
{
private:
	std::stack<int>	_stack;
public:
	RPN();
	RPN(RPN const & src);
	~RPN();

	RPN&	operator=(RPN const & src);

	void	resolve(char *expr);
	int		isOperat(char c);
	bool	checkExpr(char *expr);
};

#endif