/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/01 23:14:29 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Overload assignment operator
Fixed &Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _rawBits = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}
