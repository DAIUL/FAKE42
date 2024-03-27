#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	_thoughts = new Brain();
	std::cout << "New Cat created !" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	*this = src;
	std::cout << "New Cat copied !" << std::endl;
}

Cat::~Cat()
{
	delete _thoughts;
	std::cout << "Cat destroyed !" << std::endl;
}

Cat&	Cat::operator=(Cat const & src)
{
	if (this != &src)
	{
		type = src.GetValueStr("type");
		if (_thoughts)
			delete _thoughts;
		_thoughts = new Brain(*src.GetBrain());
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Nya Nya !" << std::endl;
}

Brain	*Cat::GetBrain() const
{
	return _thoughts;
}

void	Cat::SetThoughts(std::string idea, int i)
{
	_thoughts->SetIdeas(idea, i);
}

std::string	Cat::GetThoughts(int i) const
{
	return _thoughts->GetIdeas(i);
}