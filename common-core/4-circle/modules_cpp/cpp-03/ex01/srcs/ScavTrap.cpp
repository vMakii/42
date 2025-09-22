/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:34 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 12:15:21 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors and Destructor
ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[33mDefault ScavTrap constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardMode(false) 
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[33mScavTrap " << _name << " constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode) 
{
    std::cout << "\033[33mScavTrap copy constructor called\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    std::cout << "\033[33mScavTrap copy assignment operator called\033[0m" << std::endl;
    if (this != &other) 
    {
        ClapTrap::operator=(other);
        _guardMode = other._guardMode;
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "\033[33mScavTrap destructor called\033[0m" << std::endl;
}

// Member functions
void ScavTrap::attack(const std::string& target) 
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _energyPoints--;
        std::cout << "\033[34mScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
    } 
    else if (_hitPoints <= 0) 
    {
        std::cout << "\033[31mScavTrap " << _name << " has no hit points left to attack.\033[0m" << std::endl;
    } 
    else
    {
        std::cout << "\033[31mScavTrap " << _name << " has no energy left to attack.\033[0m" << std::endl;
    }
}

void ScavTrap::guardGate() 
{
    if (!_guardMode) 
    {
        _guardMode = true;
        std::cout << "\033[36mScavTrap " << _name << " is now in Gate Keeper mode.\033[0m" << std::endl;
    } 
    else 
    {
        std::cout << "\033[36mScavTrap " << _name << " is already in Gate Keeper mode.\033[0m" << std::endl;
    }
}