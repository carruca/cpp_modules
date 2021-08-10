#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class	PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	exit(void);
	void	add(void);
	void	search(void);
	void	printContact(void) const;
	Contact	getContact(void) const;
	void	setContact(void);

private:

	std::string	input;
	int	_size;
	Contact	_contact[8];

};

#endif
