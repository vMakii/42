/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:53:20 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:27:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors and Destructor
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getters and Setters
int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
}

// Member functions
void ClapTrap::attack(const std::string& target) 
{
    if (_energyPoints > 0 && _hitPoints > 0) 
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } 
    else if (_hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << _name << " has no hit points left to attack." << std::endl;
    } 
    else
    {
        std::cout << "ClapTrap " << _name << " has no energy left to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << _name << " is already dead and cannot take more damage." << std::endl;
        return;
    }

    _hitPoints -= amount;
    if (_hitPoints < 0) 
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitPoints << std::endl;

    if (_hitPoints == 0) 
    {
        std::cout << "ClapTrap " << _name << " has died." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (_energyPoints > 0 && _hitPoints > 0) 
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points! New hit points: " << _hitPoints << std::endl;
    } 
    else if (_hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << _name << " has no hit points left to repair itself." << std::endl;
    } 
    else
    {
        std::cout << "ClapTrap " << _name << " has no energy left to repair itself." << std::endl;
    }
}

