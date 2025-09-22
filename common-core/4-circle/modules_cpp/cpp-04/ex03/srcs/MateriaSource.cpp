/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:11:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 13:24:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors and Destructor
MateriaSource::MateriaSource() : _materiaCount(0)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    std::cout << "MateriaSource default constructor called" << std::endl;
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
    std::cout << "MateriaSource copy constructor called" << std::endl;
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
    std::cout << "MateriaSource assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materias[i];
    std::cout << "MateriaSource destructor called" << std::endl;
}

// Member functions
void MateriaSource::learnMateria(AMateria* m)
{
    if (_materiaCount < 4 && m)
    {
        _materias[_materiaCount] = m;
        _materiaCount++;
        std::cout << "Learned materia of type: " << m->getType() << std::endl;
    }
    else
    {
        std::cout << "Cannot learn more materia or invalid materia" << std::endl;
        delete m; // Prevent memory leak if materia cannot be learned
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < _materiaCount; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            std::cout << "Creating materia of type: " << type << std::endl;
            return _materias[i]->clone();
        }
    }
    std::cout << "Materia of type: " << type << " not found" << std::endl;
    return NULL;
}
