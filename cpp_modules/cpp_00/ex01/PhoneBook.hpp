#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
private:

	Contact	_contacts[8];
	int		_index;

public:

	PhoneBook(void);	
	~PhoneBook(void);

	void		DisplayPhoneBook();
	void		SetContact();
	void		DisplayContact();

};

#endif