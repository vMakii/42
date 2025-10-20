/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:09:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/20 12:50:18 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors and Destructor
Character::Character(const std::string& name) : _name(name), _inventoryCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _inventoryCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    _inventoryCount = other._inventoryCount;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
        _inventoryCount = other._inventoryCount;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

// Getters and Setters
const std::string& Character::getName() const
{
    return _name;
}

// Member functions
void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            _inventoryCount++;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
    _inventoryCount--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
