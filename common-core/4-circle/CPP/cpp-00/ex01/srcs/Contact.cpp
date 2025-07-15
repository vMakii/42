/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:09:52 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/15 14:34:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created." << std::endl;
	return ;
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,
	std::string darkestSecret) : _firstName(firstName), _lastName(lastName),
	_nickname(nickname), _phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	std::cout << "Contact created with details." << std::endl;
	return ;
}

Contact::~Contact()
{
	std::cout << "Contact destroyed." << std::endl;
	return ;
}