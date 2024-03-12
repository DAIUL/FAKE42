#include <fstream>
#include <string>
#include <iostream>
#include <ostream>

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr << "Invalid arguments" << std::endl, 0);
	
	std::ifstream 	file;
	std::ofstream	dest;
	std::string		line;
	std::string prev = std::string(av[2]);
	std::string newl = std::string(av[3]);
	size_t	index;

	file.open(std::string(av[1]));
	if (file.is_open())
	{
		dest.open(std::string(av[1]) + ".replace");
		if (dest.is_open())
		{
			while (std::getline(file, line))
			{
				for (int i = 0; i < line.size(); i++)
				{
					index = line.find(prev, i);
					if (index && index == i)
					{
						dest << newl;
						i += prev.size() - 1;
					}
					else
						dest << line[i];
				}
			}
		}
		else
			return (std::cerr << "can't open file" << std::endl, 0);
		dest.close();
	}
	else
		return (std::cerr << "can't open file" << std::endl, 0);
	file.close();
	return (0);
}