#include "Span.hpp"

int main()
{
	std::cout << "Test OK" << std::endl;

	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "###################################################" << std::endl << std::endl;

	std::cout << "Test ajout dans liste pleine" << std::endl;

	sp.addNumber(45);
	
	std::cout << std::endl << "###################################################" << std::endl << std::endl;

	std::cout << "Test tri liste vide ou 1 element" << std::endl << std::endl;

	Span	tri = Span(5);

	std::cout << tri.shortestSpan() << std::endl;
	std::cout << tri.longestSpan() << std::endl;

	sp.addNumber(6);
	
	std::cout << tri.shortestSpan() << std::endl;
	std::cout << tri.longestSpan() << std::endl;

	return 0;
}