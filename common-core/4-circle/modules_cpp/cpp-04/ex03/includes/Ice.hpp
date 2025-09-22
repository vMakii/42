/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:54:45 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 11:57:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
    public:
        // Constructors and Destructor
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual ~Ice();

        // Member functions
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};