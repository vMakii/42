/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:10:34 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/05 12:21:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int    _maxSize;
    
    public:
        // Constructors and Destructor
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        // Member functions
        void addNumber(int number);
        template<typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end);
        int shortestSpan() const;
        int longestSpan() const;
};

class SpanFullException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Span is already full";
        }
};

class NotEnoughNumbersException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Not enough numbers to find a span";
        }
};

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
    {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();
        _numbers.push_back(*it);
    }
}