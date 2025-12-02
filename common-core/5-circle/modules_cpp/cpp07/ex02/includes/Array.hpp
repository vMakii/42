/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:33:32 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/02 15:57:52 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;

    public:
        // Constructor and Destructor
        Array();
        Array(unsigned int n);
        Array(Array const& other);
        Array& operator=(Array const& other);
        ~Array();
        
        // Subscript operator for element access
        T& operator[](unsigned int index);
        T const& operator[](unsigned int index) const;
        
        // Member function
        unsigned int size() const;
};

#include "Array.tpp"