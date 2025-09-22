/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:06:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 12:06:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        int _inventoryCount;

    public:
        // Constructors and Destructor
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        // Getters and Setters
        virtual const std::string& getName() const;

        // Member functions
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};