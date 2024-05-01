#include "MutantStack.hpp"

int main()
{
	std::cout << "###########################" << std::endl;
	std::cout << "### MutantStack results ###" << std::endl;
	std::cout << "###########################" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "###########################" << std::endl;
	std::cout << "###### List  results ######" << std::endl;
	std::cout << "###########################" << std::endl;


	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	
	std::cout << mlist.back() << std::endl;
	
	mlist.pop_back();
	
	std::cout << mlist.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator sit = mlist.begin();
	std::list<int>::iterator site = mlist.end();

	++sit;
	--sit;

	while (sit != site)
	{
		std::cout << *sit << std::endl;
		++sit;
	}

	return 0;
}
