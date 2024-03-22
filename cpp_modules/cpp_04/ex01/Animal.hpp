#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(Animal const & src);
	virtual ~Animal();

	Animal&	operator=(Animal const & src);

	std::string	GetValueStr(std::string value) const;
	virtual void		makeSound() const;
	virtual void		SetThoughts(std::string idea, int i);
	virtual std::string		GetThoughts(int i) const;
};

#endif