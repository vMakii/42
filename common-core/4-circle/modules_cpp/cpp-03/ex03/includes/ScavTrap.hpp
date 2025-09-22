/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:07 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:51:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
    private:
        bool _guardMode;
    
    public:
        // Static constants for DiamondTrap
        static const unsigned int SCAV_HIT_POINTS = 100;
        static const unsigned int SCAV_ENERGY_POINTS = 50;
        static const unsigned int SCAV_ATTACK_DAMAGE = 20;

        // Constructors and Destructor
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        // Member functions
        void attack(const std::string& target);
        void guardGate();
};