#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <stdlib.h>

class ScalarConverter
{
private:

	ScalarConverter();
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter();

public:

	static void	convert(std::string value);
	static bool	isInt(std::string value);
	static bool	isFloat(std::string value);
	static bool	isDouble(std::string value);

	ScalarConverter&	operator=(ScalarConverter const & src);
};

#endif