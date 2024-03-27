#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_knowledge[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const & src);
	~MateriaSource();

	MateriaSource&	operator=(MateriaSource const & src);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
	AMateria* const & getKnowledge(int i) const;
	
};

#endif