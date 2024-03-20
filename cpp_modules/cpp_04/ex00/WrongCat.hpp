#ifndef	WRONGCAT_H
# define	WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	
public:
	WrongCat();
	WrongCat(WrongCat const & src);
	~WrongCat();

	WrongCat&	operator=(WrongCat const & src);

	void	makeSound() const;
};

#endif