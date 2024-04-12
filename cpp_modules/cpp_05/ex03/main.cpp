#include "Intern.hpp"

int	main()
{
	Bureaucrat	Serge("Serge", 3);
	Intern		Guy;

	AForm*	PoleEmploi = Guy.makeForm("Robotomy Form", "BrokeAss42Student");

	if (PoleEmploi)
	{
		PoleEmploi->beSigned(Serge);
		PoleEmploi->execute(Serge);
		delete PoleEmploi;
	}

	AForm*	Decouvert = Guy.makeForm("Decouvert bancaire", "BatMan");

	if (Decouvert)
	{
		Decouvert->beSigned(Serge);
		delete Decouvert;
	}

	return 0;
}