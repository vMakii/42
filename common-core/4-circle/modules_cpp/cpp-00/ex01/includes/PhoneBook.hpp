/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:39:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 20:50:30 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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