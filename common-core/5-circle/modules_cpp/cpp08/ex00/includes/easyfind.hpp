/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:52:09 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/05 11:01:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value);

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found in container";
        }
};

#include "easyfind.tpp"