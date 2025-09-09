/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:12 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/09 14:14:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    
    public:
        // Constructors and Destructor
        Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed(const Fixed& other);
        ~Fixed();

        // Overload assignment operator
        Fixed& operator=(const Fixed& other);
        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        // Arithmetic operators
        float operator+(const Fixed& other) const;
        float operator-(const Fixed& other) const;
        float operator*(const Fixed& other) const;
        float operator/(const Fixed& other) const;
        // Increment / Decrement operators
        Fixed& operator++();       // Prefix increment
        Fixed operator++(int);     // Postfix increment
        Fixed& operator--();       // Prefix decrement
        Fixed operator--(int);     // Postfix decrement

        // Getters and Setters
        int getRawBits() const;
        void setRawBits(int const raw);
        // Member functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        float toFloat() const;
        int toInt() const;
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


