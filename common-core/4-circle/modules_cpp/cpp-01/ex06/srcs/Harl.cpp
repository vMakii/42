/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:10:27 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/01 17:22:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
Harl::Harl(void)
{
	return;
}

/*	Destructor	*/
Harl::~Harl(void)
{
	return;
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

/*
 * Fonction pour les messages de debug
 * Niveau le plus bas de plainte
 */
void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!"
		<< std::endl;
	return;
}

/*
 * Fonction pour les messages d'information
 * Niveau informatif
 */
void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, "
		"I wouldn't be asking for more!"
		<< std::endl;
	return;
}

/*
 * Fonction pour les messages d'avertissement
 * Niveau d'avertissement
 */
void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years, whereas you started working here just last month."
		<< std::endl;
	return;
}

/*
 * Fonction pour les messages d'erreur
 * Niveau le plus élevé de plainte
 */
void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
	return;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

/*
 * Fonction principale qui gère les plaintes selon le niveau
 * Utilise un switch statement ET des pointeurs de fonctions membres
 * Affiche tous les messages à partir du niveau spécifié et au-dessus
 */
void	Harl::complain(std::string level)
{
	// Typedef pour simplifier la syntaxe des pointeurs de fonctions membres
	typedef void (Harl::*fptr)(void);
	
	// Tableaux parallèles : niveaux et pointeurs vers les fonctions correspondantes
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	fptr		complaints[4] = {&Harl::_debug, &Harl::_info, 
								&Harl::_warning, &Harl::_error};
	int			levelIndex = -1;
	
	// Trouve l'index du niveau demandé
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}
	
	// Utilise un switch statement avec des pointeurs de fonctions membres
	switch (levelIndex)
	{
		case 0: // DEBUG
			(this->*complaints[0])();
			std::cout << std::endl;
			/* FALLTHROUGH */
		case 1: // INFO
			(this->*complaints[1])();
			std::cout << std::endl;
			/* FALLTHROUGH */
		case 2: // WARNING
			(this->*complaints[2])();
			std::cout << std::endl;
			/* FALLTHROUGH */
		case 3: // ERROR
			(this->*complaints[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return;
}