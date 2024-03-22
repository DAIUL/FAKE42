#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "=============== ANIMAUX SEULS =================" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	Dog Korone;
	Cat Okayu;
	Animal*	Fuwamoco = new Dog();
	
	std::cout << Korone.GetValueStr("type") << " " << std::endl;
	std::cout << Okayu.GetValueStr("type") << " " << std::endl;

	Korone.makeSound();
	Okayu.makeSound();
	meta->makeSound();

	Korone.SetThoughts("yubi yubi !", 0);
	Okayu.SetThoughts("mogu mogu !", 0);
	Fuwamoco->SetThoughts("bau bau !", 0);

	std::cout << "Korone thinks about : " << Korone.GetThoughts(0) << std::endl;
	std::cout << "Okayu thinks about : " << Okayu.GetThoughts(0) << std::endl;
	std::cout << "Fuwamoco thinks about : " << Fuwamoco->GetThoughts(0) << std::endl;

	delete meta;
	delete Fuwamoco;
	
	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "============= TABLEAU  D'ANIMAUX ==============" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << std::endl;
	
	const Animal	*dc[6];

	for (int i = 0; i < 3; i++)
		dc[i] = new Dog();
	for (int i = 3; i < 6; i++)
		dc[i] = new Cat();
	for (int i = 0; i < 6; i++)
	{
		std::cout << dc[i]->GetValueStr("type") << " " << std::endl;
		dc[i]->makeSound();
	}

	for (int i = 0; i < 6; i++)
		delete dc[i];

	return 0;
}