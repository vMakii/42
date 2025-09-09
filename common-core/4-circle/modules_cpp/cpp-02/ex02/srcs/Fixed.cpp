/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/09 14:17:57 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : _rawBits(0) 
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() 
{
    // std::cout << "Destructor called" << std::endl;
}

// Overload assignment operator
Fixed &Fixed::operator=(const Fixed& other) 
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _rawBits = other.getRawBits();
    }
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _rawBits != other._rawBits;
}

// Arithmetic operators
float Fixed::operator+(const Fixed& other) const
{
    return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed& other) const
{
    return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed& other) const
{
    return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed& other) const
{
    return this->toFloat() / other.toFloat();
}

// Increment / Decrement operators
Fixed& Fixed::operator++()
{
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _rawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _rawBits--;
    return temp;
}

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
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

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
