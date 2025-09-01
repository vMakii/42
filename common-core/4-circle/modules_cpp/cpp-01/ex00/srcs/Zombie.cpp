/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:19:46 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 10:50:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << _name << " created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const
{
    return _name;
}
