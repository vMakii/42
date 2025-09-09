/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/09 14:05:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : _rawBits(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
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

// Comparison operators

// Arithmetic operators

// Increment / Decrement operators



// Getters and Setters
int Fixed::getRawBits() const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

// Member functions
float Fixed::toFloat() const
{
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _rawBits >> _fractionalBits;
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
