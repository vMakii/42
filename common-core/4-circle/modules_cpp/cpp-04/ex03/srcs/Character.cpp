/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:09:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 12:10:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors and Destructor
Character::Character(const std::string& name) : _name(name), _inventoryCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character parameterized constructor called for: " << _name << std::endl;
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
    std::cout << "Character copy constructor called for: " << _name << std::endl;
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
    std::cout << "Character assignment operator called for: " << _name << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    std::cout << "Character destructor called for: " << _name << std::endl;
}

// Getters and Setters
const std::string& Character::getName() const
{
    return _name;
}

// Member functions
void Character::equip(AMateria* m)
{
    if (_inventoryCount >= 4)
    {
        std::cout << "Inventory full, cannot equip more materia." << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            _inventoryCount++;
            std::cout << "Equipped materia: " << m->getType() << " to character: " << _name << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Invalid index or empty slot, cannot unequip." << std::endl;
        return;
    }
    std::cout << "Unequipped materia: " << _inventory[idx]->getType() << " from character: " << _name << std::endl;
    _inventory[idx] = NULL;
    _inventoryCount--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Invalid index or empty slot, cannot use materia." << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}
