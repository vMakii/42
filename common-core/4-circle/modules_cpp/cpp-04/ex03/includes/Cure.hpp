/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:56:15 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 11:57:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
    public:
        // Constructors and Destructor
        Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        virtual ~Cure();

        // Member functions
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};