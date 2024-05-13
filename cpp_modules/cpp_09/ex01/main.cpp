#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2) {
		std::cout << "Bad arguments, should be : ./RNP [rpn expression]" << std::endl;
		return 0;
	}
	if (rpn.checkExpr(av[1]))
		rpn.resolve(av[1]);
	return 0;
}