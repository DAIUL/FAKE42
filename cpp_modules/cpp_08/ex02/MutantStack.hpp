#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(): std::stack<T>() {}
	MutantStack(MutantStack const & src) { *this = src; }
	~MutantStack() {}

	MutantStack&	operator=(MutantStack const & src) {
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator	begin() {
		return this->c.begin();
	}

	iterator	end() {
		return this->c.end();
	}
};

#endif