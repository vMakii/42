#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _contactCount;
	int _nextIndex;

  public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContacts() const;
	void displayContacts() const;
	void displayContact(int index) const;
	std::string truncateString(const std::string &str) const;
};

#endif