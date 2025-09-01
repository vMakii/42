/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:30:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 11:53:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        std::cerr << "Error: Number of zombies must be greater than one." << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N];
    if (!horde)
    {
        std::cerr << "Error: Memory allocation failed." << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; ++i)
    {
        std::stringstream ss;
        ss << name << " " << (i + 1);
        horde[i].setName(ss.str());
    }
    return horde;
}