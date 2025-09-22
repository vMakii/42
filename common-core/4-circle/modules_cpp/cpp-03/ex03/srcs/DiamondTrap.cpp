/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:51:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors and Destructor
DiamondTrap::DiamondTrap() : ClapTrap(), _name("Default") 
{
    ClapTrap::_name = _name + "_clap_name";
    // Use static constants from parent classes
    _hitPoints = FragTrap::FRAG_HIT_POINTS;        // FragTrap's hit points (100)
    _energyPoints = ScavTrap::SCAV_ENERGY_POINTS;  // ScavTrap's energy points (50)
    _attackDamage = FragTrap::FRAG_ATTACK_DAMAGE;  // FragTrap's attack damage (30)
    std::cout << "\033[35mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) 
{
    // Use static constants from parent classes
    _hitPoints = FragTrap::FRAG_HIT_POINTS;        // FragTrap's hit points (100)
    _energyPoints = ScavTrap::SCAV_ENERGY_POINTS;  // ScavTrap's energy points (50)
    _attackDamage = FragTrap::FRAG_ATTACK_DAMAGE;  // FragTrap's attack damage (30)
    std::cout << "\033[35mDiamondTrap " << _name << " constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) 
{
    std::cout << "\033[35mDiamondTrap copy constructor called\033[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
    std::cout << "\033[35mDiamondTrap copy assignment operator called\033[0m" << std::endl;
    if (this != &other) 
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "\033[35mDiamondTrap destructor called\033[0m" << std::endl;
}

// Member functions
void DiamondTrap::whoAmI() 
{
    std::cout << "\033[35mDiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << "\033[0m" << std::endl;
}