#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
private:
	std::string	_ideas [100];
public:
	Brain();
	Brain(Brain const & src);
	~Brain();

	Brain&	operator=(Brain const & src);

	std::string	GetIdeas(int i) const;
	void		SetIdeas(std::string idea, int i);
};

#endif