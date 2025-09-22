/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:18:13 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:51:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap 
{
    public:
        // Static constants for DiamondTrap
        static const unsigned int FRAG_HIT_POINTS = 100;
        static const unsigned int FRAG_ENERGY_POINTS = 100;
        static const unsigned int FRAG_ATTACK_DAMAGE = 30;

        // Constructors and Destructor
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        // Member functions
        void highFivesGuys();
};