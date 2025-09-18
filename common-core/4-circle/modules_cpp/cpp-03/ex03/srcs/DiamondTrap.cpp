/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:58:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/18 16:58:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors and Destructor
DiamondTrap::DiamondTrap() : ClapTrap(), _name("Default") 
{
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;       // 100
    _energyPoints = ScavTrap::_energyPoints; // 50
    _attackDamage = FragTrap::_attackDamage; // 30
    std::cout << "\033[35mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) 
{
    _hitPoints = FragTrap::_hitPoints;       // 100
    _energyPoints = ScavTrap::_energyPoints; // 50
    _attackDamage = FragTrap::_attackDamage; // 30
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

// Note: Using ScavTrap's attack method as specified in the header file