#include "Serializer.hpp"

int main()
{
	Data	info;
	info.data = 12;
	
	uintptr_t	seri = Serializer::serialize(&info);

	std::cout << "seri : " << seri << std::endl;

	Data	*deseri = Serializer::deserialize(seri);

	if (deseri == &info)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;

	return 0;
}