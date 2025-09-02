/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:10:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 21:04:19 by mivogel          ###   ########.fr       */
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
	
	this->displaySeparator();
	std::cout << "AJOUTER UN NOUVEAU CONTACT" << std::endl;
	this->displaySeparator();
	
	std::cout << "Prenom: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "Le prenom ne peut pas etre vide. Prenom: ";
		std::getline(std::cin, firstName);
	}
	
	std::cout << "Nom: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Le nom ne peut pas etre vide. Nom: ";
		std::getline(std::cin, lastName);
	}
	
	std::cout << "Surnom: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Le surnom ne peut pas etre vide. Surnom: ";
		std::getline(std::cin, nickname);
	}
	
	std::cout << "Numero de telephone: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Le numero ne peut pas etre vide. Numero: ";
		std::getline(std::cin, phoneNumber);
	}
	
	std::cout << "Secret le plus sombre: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Le secret ne peut pas etre vide. Secret: ";
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
	
	this->displaySeparator();
	std::cout << "Contact ajoute avec succes!" << std::endl;
	this->displaySeparator();
}

void PhoneBook::searchContacts() const
{
	if (this->_contactCount == 0)
	{
		this->displaySeparator();
		std::cout << "Le carnet d'adresses est vide!" << std::endl;
		std::cout << "Utilisez la commande ADD pour ajouter un contact." << std::endl;
		this->displaySeparator();
		return ;
	}

	this->displaySeparator();
	std::cout << "RECHERCHE DE CONTACTS" << std::endl;
	this->displaySeparator();
	
	this->displayContacts();

	std::string input;
	int index;

	std::cout << std::endl << "Entrez l'index du contact a afficher (1-8): ";
	std::getline(std::cin, input);

	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
	{
		index = input[0] - '1';
		if (index < this->_contactCount)
			this->displayContact(index);
		else
		{
			std::cout << "Aucun contact a cet index!" << std::endl;
		}
	}
	else
	{
		std::cout << "Index invalide! Veuillez entrer un nombre entre 1 et 8." << std::endl;
	}
	this->displaySeparator();
}

void PhoneBook::displayContacts() const
{
	std::cout << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+" 
			  << std::string(10, '-') << "+" << std::string(10, '-') << "+" << std::endl;
	
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "Prenom"
			  << "|" << std::setw(10) << "Nom"
			  << "|" << std::setw(10) << "Surnom" << "|" << std::endl;
			  
	std::cout << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+" 
			  << std::string(10, '-') << "+" << std::string(10, '-') << "+" << std::endl;

	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 
				  << "|" << std::setw(10) << this->truncateString(this->_contacts[i].getFirstName())
				  << "|" << std::setw(10) << this->truncateString(this->_contacts[i].getLastName())
				  << "|" << std::setw(10) << this->truncateString(this->_contacts[i].getNickname()) << "|" << std::endl;
	}
	
	std::cout << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+" 
			  << std::string(10, '-') << "+" << std::string(10, '-') << "+" << std::endl;
}

void PhoneBook::displayContact(int index) const
{
	std::cout << std::endl;
	std::cout << "+================================================================+" << std::endl;
	std::cout << "|                        DETAILS DU CONTACT                     |" << std::endl;
	std::cout << "+================================================================+" << std::endl;
	std::cout << "| Prenom         : " << std::left << std::setw(44) << this->_contacts[index].getFirstName() << " |" << std::endl;
	std::cout << "| Nom            : " << std::left << std::setw(44) << this->_contacts[index].getLastName() << " |" << std::endl;
	std::cout << "| Surnom         : " << std::left << std::setw(44) << this->_contacts[index].getNickname() << " |" << std::endl;
	std::cout << "| Telephone      : " << std::left << std::setw(44) << this->_contacts[index].getPhoneNumber() << " |" << std::endl;
	std::cout << "| Secret sombre  : " << std::left << std::setw(44) << this->_contacts[index].getDarkestSecret() << " |" << std::endl;
	std::cout << "+================================================================+" << std::endl;
}

std::string PhoneBook::truncateString(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::displayWelcome() const
{
	std::cout << "+==================================================================+" << std::endl;
	std::cout << "|                                                                  |" << std::endl;
	std::cout << "|                     CARNET D'ADRESSES                           |" << std::endl;
	std::cout << "|                                                                  |" << std::endl;
	std::cout << "|                    Bienvenue dans votre                         |" << std::endl;
	std::cout << "|                   PhoneBook personnel !                         |" << std::endl;
	std::cout << "|                                                                  |" << std::endl;
	std::cout << "+==================================================================+" << std::endl;
}

void PhoneBook::displayMainMenu() const
{
	std::cout << std::endl;
	std::cout << "+-----------------------------------------------------------------+" << std::endl;
	std::cout << "|                        MENU PRINCIPAL                          |" << std::endl;
	std::cout << "+-----------------------------------------------------------------+" << std::endl;
	std::cout << "|  ADD    - Ajouter un nouveau contact                           |" << std::endl;
	std::cout << "|  SEARCH - Rechercher et afficher les contacts                  |" << std::endl;
	std::cout << "|  EXIT   - Quitter l'application                                |" << std::endl;
	std::cout << "+-----------------------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	std::cout << "Entrez votre commande: ";
}

void PhoneBook::displaySeparator() const
{
	std::cout << std::string(68, '=') << std::endl;
}

void PhoneBook::displayHeader() const
{
	// Méthode vide - plus d'affichage du nombre de contacts
}