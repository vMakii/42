/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:19:51 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/19 18:13:51 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors and Destructor
AAnimal::AAnimal() : type("Animal") 
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) 
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) 
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

// Getters and Setters
std::string AAnimal::getType() const
{
    return type;
}

// Member functions
// makeSound is pure virtual in AAnimal
