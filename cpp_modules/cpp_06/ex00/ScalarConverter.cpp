#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter() {
}

bool	ScalarConverter::isInt(std::string value)
{
	for (int i = 0; i < (int)value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		else if (!std::isdigit(value[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(std::string value)
{
	int	dot = value.find(".");
	int	fract = value.find("f");

	if (fract == -1 || dot == -1)
		return false;

	for (int i = 0; i < (int)value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		else if (!std::isdigit(value[i]) && (i != dot && i != fract))
			return false;
	}
	return true;
}

bool	ScalarConverter::isDouble(std::string value)
{
	int	dot = value.find(".");

	if (dot == -1)
		return false;

	for (int i = 0; i < (int)value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		else if (!std::isdigit(value[i]) && i != dot)
			return false;
	}
	return true;
}

void ScalarConverter::convert(std::string value)
{
	const std::string	pseudo_value[6] = {"-inff", "-inf", "nanf", "nan", "+inff", "+inf"};

	if (value.length() == 1 && (value[0] < 32 || value[0] > 126))
		return (std::cout << "Non displayable characters are not accepted as an input..." << std::endl, (void)0);

	if (value.length() == 1 && !std::isdigit(value[0]))
	{
		std::cout << "Char : " << value << std::endl;
		std::cout << "Int : " << static_cast<int>(value[0]) << std::endl;
		std::cout << "Float : " << static_cast<float>(value[0]) << std::endl;
		std::cout << "Double : " << static_cast<double>(value[0]) << std::endl;
	}
	else if (isInt(value))
	{
		int	transfer = atoi(value.c_str());

		if (transfer >= 32 && transfer <= 126)
			std::cout << "Char : " << static_cast<char>(transfer) << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;

		std::cout << "Int : " << static_cast<int>(transfer) << std::endl;
		std::cout << "Float : " << static_cast<float>(transfer) << ".0f" << std::endl;
		std::cout << "Double : " << static_cast<double>(transfer) << ".0" << std::endl;
	}
	else if (isFloat(value))
	{
		float	transfer = atof(value.c_str());

		if (static_cast<int>(transfer) >= 32 && static_cast<int>(transfer) <= 126)
			std::cout << "Char : '" << static_cast<char>(transfer) << "'" << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;

		std::cout << "Int : " << static_cast<int>(transfer) << std::endl;
		std::cout << "Float : " << transfer << (transfer - static_cast<int>(transfer) == 0 ? ".0f" : "f") << std::endl;
		std::cout << "Double : " << static_cast<double>(transfer) << (transfer - static_cast<int>(transfer) == 0 ? ".0" : "") << std::endl;
	}
	else if (isDouble(value))
	{
		double	transfer = atof(value.c_str());

		if (static_cast<int>(transfer) >= 32 && static_cast<int>(transfer) <= 126)
			std::cout << "Char : '" << static_cast<char>(transfer) << "'" << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;

		std::cout << "Int : " << static_cast<int>(transfer) << std::endl;
		std::cout << "Float : " << static_cast<float>(transfer) << (transfer - static_cast<int>(transfer) == 0 ? ".0f" : "f") << std::endl;
		std::cout << "Double : " << transfer << (transfer - static_cast<int>(transfer) == 0 ? ".0" : "") << std::endl;
	}
	else
	{
		int	i;

		for (i = 0; i < 6; i++)
			if (value == pseudo_value[i])
				break;
		if (i != 6)
		{
			std::cout << "Char : impossible" << std::endl;
			std::cout << "Int : impossible" << std::endl;

			if (i % 2 == 0)
			{
				std::cout << "Float : " << pseudo_value[i] << std::endl;	
				std::cout << "Double : " << pseudo_value[i + 1] << std::endl;	
			}
			else
			{
				std::cout << "Float : " << pseudo_value[i - 1] << std::endl;
				std::cout << "Double : " << pseudo_value[i] << std::endl;
			}
		}
		else
			std::cout << "Please use a valid input : Char, Int, Float or Double" << std::endl;
	}
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
	return *this;
}