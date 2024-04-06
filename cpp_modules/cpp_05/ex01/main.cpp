#include "Form.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 3);
	Bureaucrat	Rene("Rene", 0);
	Form		divorce("Divorce", 50, 50);
	Form		donOrgane("DonOrgane", 1, 50);
	Form		travail("Travail", 1, 155);

	Serge.upGrade();
	Serge.downGrade();
	std::cout << Serge << std::endl;
	divorce.beSigned(Rene);
	divorce.beSigned(Serge);
	donOrgane.beSigned(Serge);

	std::cout << Serge << std::endl;
	std::cout << divorce << std::endl;
	std::cout << donOrgane << std::endl;
	std::cout << travail << std::endl;

	return 0;
}