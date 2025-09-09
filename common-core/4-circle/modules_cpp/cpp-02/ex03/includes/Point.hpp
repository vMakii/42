/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:07 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/09 14:57:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point 
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        // Constructors and Destructor
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();

        // Overload assignment operator
        Point& operator=(const Point& other);

        // Getters
        Fixed getX() const;
        Fixed getY() const;
};