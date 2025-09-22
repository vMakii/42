/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:09:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:02:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Simple floor to collect unequipped materias and delete at program end
namespace {
    struct FloorCollector {
        AMateria* items[1024];
        int count;
        FloorCollector(): items(), count(0) {}
        ~FloorCollector(){ for(int i=0;i<count;i++) delete items[i]; }
        void drop(AMateria* m){ if(!m) return; if(count < 1024) items[count++] = m; else delete m; }
    } g_floor;
}

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
    // inventory full, silently ignore as per subject (no delete)
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    // drop on the floor (do not delete as per subject)
    g_floor.drop(_inventory[idx]);
    _inventory[idx] = NULL;
    _inventoryCount--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
