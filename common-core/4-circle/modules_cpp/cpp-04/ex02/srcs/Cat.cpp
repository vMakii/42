/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:31:40 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/19 18:13:51 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors and Destructor
Cat::Cat() : AAnimal() 
{
    type = "Cat";
    _brain = new Brain();
    if (!_brain)
    {
        std::cerr << "Failed to allocate memory for Brain" << std::endl;
        exit(1);
    }
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) 
{
    _brain = new Brain(*other._brain);
    if (!_brain)
    {
        std::cerr << "Failed to allocate memory for Brain" << std::endl;
        exit(1);
    }
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other); // Call base class assignment
        if (_brain)
            *_brain = *other._brain;
    }
    return *this;
}

Cat::~Cat() 
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

// Member functions
void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}
