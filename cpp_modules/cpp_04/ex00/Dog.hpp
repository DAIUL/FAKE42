#ifndef	DOG_H
# define	DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
private:
	
public:
	Dog();
	Dog(Dog const & src);
	~Dog();

	Dog&	operator=(Dog const & src);

	void	makeSound() const;
};

#endif