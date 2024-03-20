#ifndef	Cat_H
# define	Cat_H

#include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat();
	Cat(Cat const & src);
	~Cat();

	Cat&	operator=(Cat const & src);

	void	makeSound() const;
};

#endif