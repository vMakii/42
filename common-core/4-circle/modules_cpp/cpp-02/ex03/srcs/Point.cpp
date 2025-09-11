/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:30 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/11 09:49:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and Destructor
Point::Point() : _x(0), _y(0) 
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) 
{
    // std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) 
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() 
{
    // std::cout << "Destructor called" << std::endl;
}

// Overload assignment operator
Point& Point::operator=(const Point& other) 
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        // Since _x and _y are const, we cannot assign to them.
        // This operator is effectively a no-op in this case.
        // Alternatively, we could throw an exception or handle it differently.
    }
    return *this;
}

// Getters
Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}
