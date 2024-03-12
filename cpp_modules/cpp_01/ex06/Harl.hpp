#include <iostream>
#include <ostream>
#include <string>

class Harl
{
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
public:
	Harl();
	~Harl();

	std::string	lvl[4];
	void	(Harl::*ptr[4])(void);
	
	void	complain(std::string level);
	int		which_lvl(std::string level);
};