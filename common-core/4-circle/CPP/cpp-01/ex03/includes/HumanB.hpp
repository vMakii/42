/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/11 12:46:15 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;  // Pointeur

	public:
		HumanB(const std::string &name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack() const;
};
