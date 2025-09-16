/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:27:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 11:31:21 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors and Destructor
Dog::Dog() : Animal() 
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}
