#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "New MateriaSource created !" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_knowledge[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
	std::cout << "New MateriaSource copied !" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_knowledge[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destroyed !" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_knowledge[i])
			delete _knowledge[i];
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_knowledge[i])
				delete _knowledge[i];
			_knowledge[i] = src.getKnowledge(i);
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_knowledge[i])
		{
			_knowledge[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
	{
		for (int i = 0; i < 4; i++)
		{
			if (_knowledge[i]->getType() == "ice")
				return _knowledge[i]->clone();
		}
	}
	else if (type == "cure")
	{
		for (int i = 0; i < 4; i++)
		{
			if (_knowledge[i]->getType() == "cure")
				return _knowledge[i]->clone();
		}
	}
	return 0;
}

AMateria* const & MateriaSource::getKnowledge(int i) const
{
	return _knowledge[i];
}