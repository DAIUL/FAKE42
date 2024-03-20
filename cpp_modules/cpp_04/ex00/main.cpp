#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog* k = new Dog();
	const Cat* l = new Cat();

	std::cout << j->GetValueStr("type") << " " << std::endl;
	std::cout << i->GetValueStr("type") << " " << std::endl;
	std::cout << k->GetValueStr("type") << " " << std::endl;
	std::cout << l->GetValueStr("type") << " " << std::endl;
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;

	return 0;
}