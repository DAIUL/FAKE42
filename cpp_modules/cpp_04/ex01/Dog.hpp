#ifndef	DOG_H
# define	DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_thoughts;
public:
	Dog();
	Dog(Dog const & src);
	~Dog();

	Dog&	operator=(Dog const & src);

	void	makeSound() const;
	Brain	*GetBrain() const;
	void	SetThoughts(std::string idea, int i);
	std::string	GetThoughts(int i) const;
};

#endif