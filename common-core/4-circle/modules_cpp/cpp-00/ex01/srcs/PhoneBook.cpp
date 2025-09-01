/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:10:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 21:54:36 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "First name cannot be empty. Enter first name: ";
		std::getline(std::cin, firstName);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Last name cannot be empty. Enter last name: ";
		std::getline(std::cin, lastName);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Enter nickname: ";
		std::getline(std::cin, nickname);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Phone number cannot be empty. Enter phone number: ";
		std::getline(std::cin, phoneNumber);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret cannot be empty. Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}
	this->_contacts[this->_nextIndex].setFirstName(firstName);
	this->_contacts[this->_nextIndex].setLastName(lastName);
	this->_contacts[this->_nextIndex].setNickname(nickname);
	this->_contacts[this->_nextIndex].setPhoneNumber(phoneNumber);
	this->_contacts[this->_nextIndex].setDarkestSecret(darkestSecret);
	this->_nextIndex = (this->_nextIndex + 1) % 8;
	if (this->_contactCount < 8)
		this->_contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const
{
	if (this->_contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}

	this->displayContacts();

	std::string input;
	int index;

	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);

	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		index = input[0] - '0';
		if (index < this->_contactCount)
			this->displayContact(index);
		else
			std::cout << "No contact at this index!" << std::endl;
	}
	else
		std::cout << "Invalid index! Please enter a number between 0 and 7." << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->truncateString(this->_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << this->truncateString(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << this->truncateString(this->_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateString(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}