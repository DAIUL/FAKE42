#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "New Brain created !" << std::endl;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout << "New Brain copied !" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed !" << std::endl;
}

Brain&	Brain::operator=(Brain const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = src.GetIdeas(i);
	}
	return *this;
}

std::string	Brain::GetIdeas(int i) const
{
	return _ideas[i];
}

void	Brain::SetIdeas(std::string idea, int i)
{
	_ideas[i] = idea;
}