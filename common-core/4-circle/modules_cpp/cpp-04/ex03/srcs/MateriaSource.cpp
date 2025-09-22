/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:11:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 15:02:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors and Destructor
MateriaSource::MateriaSource() : _materiaCount(0)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _materiaCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    _materiaCount = other._materiaCount;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _materias[i];
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
        _materiaCount = other._materiaCount;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materias[i];
}

// Member functions
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    if (_materiaCount < 4)
    {
        _materias[_materiaCount] = m->clone();
        _materiaCount++;
    }
    delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < _materiaCount; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
