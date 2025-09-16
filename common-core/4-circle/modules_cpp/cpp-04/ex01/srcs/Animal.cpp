/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:19:51 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 11:24:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors and Destructor
Animal::Animal() : type("Animal") 
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) 
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) 
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

// Getters and Setters
std::string Animal::getType() const
{
    return type;
}

// Member functions
void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}
