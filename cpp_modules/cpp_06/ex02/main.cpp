#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	srand(time(NULL));

	int random = rand() % 3;

	switch(random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type : C" << std::endl;
	else
		std::cout << "Type : Unknown" << std::endl;
}

void	identify(Base& p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type : A" << std::endl;
	} catch (std::exception& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Type : B" << std::endl;
		} catch (std::exception& e) {
			try {
				C& c = dynamic_cast<C&>(p);
			(void)c;
				std::cout << "Type : C" << std::endl;
			} catch (std::exception& e) {
				std::cout << "Type : Unknown" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base	*base = generate();

	std::cout << "Pointer identifier -> ";
	identify(base);
	std::cout << "Reference identifier -> ";
	identify(*base);

	return 0;
}