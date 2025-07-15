#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _oldest;

  public:
	PhoneBook();
	~PhoneBook();
};

#endif