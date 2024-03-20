#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog* k = new Dog();
	const Cat* l = new Cat();
	const WrongAnimal* m = new WrongCat();
	const WrongCat* n = new WrongCat();

	std::cout << j->GetValueStr("type") << " " << std::endl;
	std::cout << i->GetValueStr("type") << " " << std::endl;
	std::cout << k->GetValueStr("type") << " " << std::endl;
	std::cout << l->GetValueStr("type") << " " << std::endl;
	std::cout << m->GetValueStr("type") << " " << std::endl;
	std::cout << n->GetValueStr("type") << " " << std::endl;
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	m->makeSound();
	n->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	delete m;
	delete n;

	return 0;
}