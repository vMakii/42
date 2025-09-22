/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:42:13 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 11:41:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors and Destructor
AMateria::AMateria(const std::string& type) : _type(type)
{
    std::cout << "AMateria parameterized constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called for type: " << _type << std::endl;
}

// Getters and Setters
const std::string& AMateria::getType() const
{
    return _type;
}

// Member functions
void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}