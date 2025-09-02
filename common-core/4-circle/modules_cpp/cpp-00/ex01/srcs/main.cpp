/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 21:04:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string command;
	
	phoneBook.displayWelcome();
	
	while (true)
	{
		phoneBook.displayMainMenu();
		std::getline(std::cin, command);
		
		if (std::cin.eof())
		{
			std::cout << std::endl << "EOF detecte. Fermeture..." << std::endl;
			break ;
		}
		
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContacts();
		}
		else if (command == "EXIT")
		{
			phoneBook.displaySeparator();
			std::cout << "Au revoir et a bientot!" << std::endl;
			phoneBook.displaySeparator();
			break ;
		}
		else if (!command.empty())
		{
			phoneBook.displaySeparator();
			std::cout << "Commande inconnue: '" << command << "'" << std::endl;
			std::cout << "Commandes disponibles: ADD, SEARCH, EXIT" << std::endl;
			phoneBook.displaySeparator();
		}
	}
	return (0);
}
