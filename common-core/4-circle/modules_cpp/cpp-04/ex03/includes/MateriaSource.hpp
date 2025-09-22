/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:11:19 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 12:12:26 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];
        int _materiaCount;

    public:
        // Constructors and Destructor
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual ~MateriaSource();

        // Member functions
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(const std::string& type);
};