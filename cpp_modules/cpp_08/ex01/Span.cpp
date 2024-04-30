#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int nb) : _limit(nb) {}
Span::Span(Span const & src) { *this = src;}
Span::~Span() {}

void	Span::addNumber(unsigned int nb)
{
	try {
		if (_nb.size() < _limit)
		{
			_nb.push_back(nb);
			return ;
		}
		throw Span::TooMany();
	} 
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}

void	Span::addMulti(std::vector<unsigned int> add) {
	try {
		if ((add.size() + _nb.size()) > _limit)
			throw Span::TooMany();
		else {
			for (std::vector<unsigned int>::iterator it = add.begin(); it != add.end(); it++)
				_nb.push_back(*it);
		}
	} catch (std::exception& e) {
		std::cerr << e.what();
	}
}

unsigned int	Span::longestSpan() {
	try {
		if (_nb.size() < 3)
			throw Span::NotEnough();
		else {
			std::vector<unsigned int> tri = getNb();
			std::sort(tri.begin(), tri.end());
			
			std::vector<unsigned int>::iterator it = tri.begin();
			unsigned int a = *it;
			std::advance(it, tri.size() - 1);
			unsigned int b = *it;

			return (b - a);
		}
	} catch (std::exception& e) {
		std::cerr << e.what();
		return 0;
	}
}

unsigned int	Span::shortestSpan() {
	try {
		if (_nb.size() < 3)
			throw Span::NotEnough();
		else {
			std::vector<unsigned int> tri = getNb();
			std::sort(tri.begin(), tri.end());
			unsigned int res = tri[1] - tri[0];

			for (unsigned int i = 1; i < tri.size(); i++) {
				if ((tri[i + 1] - tri[i]) < res)
					res = tri[i + 1] - tri[i];
			}

			return res;
		}
	} catch (std::exception& e) {
		std::cerr << e.what();
		return 0;
	}
}

unsigned int	Span::getLimit() const {
	return _limit;
}

std::vector<unsigned int>	Span::getNb() {
	std::vector<unsigned int>	nouvo;
	for (std::vector<unsigned int>::iterator it = _nb.begin(); it != _nb.end(); it++)
		nouvo.push_back(*it);
	return nouvo;
}

Span&	Span::operator=(Span const & src)
{
	if (this != &src)
	{
		_limit = src.getLimit();
		std::vector<unsigned int>	nouvo;
		for (std::vector<unsigned int>::iterator it = _nb.begin(); it != _nb.end(); it++)
		nouvo.push_back(*it);
		_nb = nouvo;
	}
	return *this;
}