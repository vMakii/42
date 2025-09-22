/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:30:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:02:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ICharacter; // Forward declaration

class AMateria
{
    protected:
        // Make type immutable to reflect that copying type on assignment is pointless
        const std::string _type; // The type of the materia

    public:
        // Constructors and Destructor
        AMateria(const std::string& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        // Getters and Setters
        const std::string& getType() const; // Returns the materia type

        // Member functions
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};