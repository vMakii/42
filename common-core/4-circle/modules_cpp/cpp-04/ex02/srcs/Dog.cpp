/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:27:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/19 21:56:57 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors and Destructor
Dog::Dog() : AAnimal() 
{
    type = "Dog";
    _brain = new Brain();
    if (!_brain)
    {
        std::cerr << "Failed to allocate memory for Brain" << std::endl;
        exit(1);
    }
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) 
{
    _brain = new Brain(*other._brain);
    if (!_brain)
    {
        std::cerr << "Failed to allocate memory for Brain" << std::endl;
        exit(1);
    }
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        AAnimal::operator=(other); // Call base class assignment
        if (_brain)
            *_brain = *other._brain;
    }
    return *this;
}

Dog::~Dog() 
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}
