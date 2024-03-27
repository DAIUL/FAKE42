#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(Ice const & src);
	~Ice();

	Ice&	operator=(Ice const & src);
	
	void 		use(ICharacter& target);
	AMateria* 	clone() const;
};

#endif