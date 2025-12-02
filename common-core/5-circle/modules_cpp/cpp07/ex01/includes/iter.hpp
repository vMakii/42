/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:17:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/02 15:19:14 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T, typename Func>
void iter(T* array, size_t const length, Func func)
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}