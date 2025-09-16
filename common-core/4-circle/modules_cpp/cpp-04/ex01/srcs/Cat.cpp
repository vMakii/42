/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:31:40 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 11:32:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors and Destructor
Cat::Cat() : Animal() 
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        type = other.type;
    }
    return *this;
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
}

// Member functions
void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}
