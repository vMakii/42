/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:42:13 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:02:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors and Destructor
AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    // _type is immutable; nothing to assign
    (void)other;
    return *this;
}

AMateria::~AMateria() {}

// Getters and Setters
const std::string& AMateria::getType() const
{
    return _type;
}

// Member functions
void AMateria::use(ICharacter& target)
{
    // default implementation does nothing visible per subject
    (void)target;
}