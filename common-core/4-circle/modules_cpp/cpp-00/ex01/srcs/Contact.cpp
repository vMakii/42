/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:09:52 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 21:25:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,
	std::string darkestSecret) : _firstName(firstName), _lastName(lastName),
	_nickname(nickname), _phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	return ;
}

Contact::~Contact()
{
	return ;
}

// Getters
std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickname() const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

// Setters
void Contact::setFirstName(const std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}