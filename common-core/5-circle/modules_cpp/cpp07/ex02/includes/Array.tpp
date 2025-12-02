/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:40:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/02 15:58:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Constructor and Destructor
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const& other) : _elements(NULL), _size(0)
{
    if (other._size > 0)
    {
        _elements = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; ++i)
        {
            _elements[i] = other._elements[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
    if (this != &other)
    {
        // Libère l'ancienne mémoire
        delete[] _elements;
        
        _size = other._size;
        if (_size > 0)
        {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
            {
                _elements[i] = other._elements[i];
            }
        }
        else
        {
            _elements = NULL;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _elements;
}

// Subscript operator for element access
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return _elements[index];
}

template <typename T>
T const& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return _elements[index];
}

// Member function
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
