/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/09 11:34:49 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intValue << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatValue * (1 << _fractionalBits));
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

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{
    return _rawBits;
}

// Setter
void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

// Convert to float
float Fixed::toFloat() const
{
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt() const
{
    return _rawBits >> _fractionalBits;
}
