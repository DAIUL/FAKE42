#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const & src);
	~WrongAnimal();

	WrongAnimal&	operator=(WrongAnimal const & src);

	std::string	GetValueStr(std::string value) const;
	void		makeSound() const;
};

#endif