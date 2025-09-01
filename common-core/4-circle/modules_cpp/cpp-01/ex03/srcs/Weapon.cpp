/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/11 12:22:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
