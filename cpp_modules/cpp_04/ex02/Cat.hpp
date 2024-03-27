#ifndef	Cat_H
# define	Cat_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_thoughts;
public:
	Cat();
	Cat(Cat const & src);
	~Cat();

	Cat&	operator=(Cat const & src);

	void	makeSound() const;
	Brain	*GetBrain() const;	
	void	SetThoughts(std::string idea, int i);
	std::string	GetThoughts(int i) const;
};

#endif