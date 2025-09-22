/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:17:45 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:51:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors and Destructor
FragTrap::FragTrap() : ClapTrap() 
{
    _hitPoints = FRAG_HIT_POINTS;
    _energyPoints = FRAG_ENERGY_POINTS;
    _attackDamage = FRAG_ATTACK_DAMAGE;
    std::cout << "\033[31mDefault FragTrap constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _hitPoints = FRAG_HIT_POINTS;
    _energyPoints = FRAG_ENERGY_POINTS;
    _attackDamage = FRAG_ATTACK_DAMAGE;
    std::cout << "\033[31mFragTrap " << _name << " constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "\033[31mFragTrap copy constructor called\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    std::cout << "\033[31mFragTrap copy assignment operator called\033[0m" << std::endl;
    if (this != &other) 
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() 
{
    std::cout << "\033[31mFragTrap destructor called\033[0m" << std::endl;
}

// Member functions
void FragTrap::highFivesGuys() 
{
    std::cout << "\033[31mFragTrap " << _name << " : High five, guys! ✋\033[0m" << std::endl;
}