#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	std::vector<unsigned int>	_nb;
	unsigned int				_limit;
	Span();
public:
	Span(unsigned int nb);
	Span(Span const & src);
	~Span();

	void						addNumber(unsigned int nb);
	void						addMulti(std::vector<unsigned int> add);
	std::vector<unsigned int>	getNb();
	unsigned int				getLimit() const;
	unsigned int				longestSpan();
	unsigned int				shortestSpan();

	Span&	operator=(Span const & src);

	class TooMany : public std::exception {
	public :
		virtual const char *what() const throw() {
			return "Too many elements in the container...\n";
		}
	};

	class NotEnough : public std::exception {
	public :
		virtual const char *what() const throw() {
			return "Lack of elements to get a result...\n";
		}
	};
};

#endif