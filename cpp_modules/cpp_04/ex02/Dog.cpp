#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	_thoughts = new Brain();
	std::cout << "New Dog created !" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	*this = src;
	std::cout << "New Dog copied !" << std::endl;
}

Dog::~Dog()
{
	delete _thoughts;
	std::cout << "Dog destroyed !" << std::endl;
}

Dog&	Dog::operator=(Dog const & src)
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

void	Dog::makeSound() const
{
	std::cout << "Wan Wan !" << std::endl;
}

Brain	*Dog::GetBrain() const
{
	return _thoughts;
}

void	Dog::SetThoughts(std::string idea, int i)
{
	_thoughts->SetIdeas(idea, i);
}

std::string	Dog::GetThoughts(int i) const
{
	return _thoughts->GetIdeas(i);
}