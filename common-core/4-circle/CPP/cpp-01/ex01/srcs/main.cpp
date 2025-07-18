/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:38:12 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 11:50:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "=== Testing Zombie Horde Creation ===" << std::endl;
    int N = 10;
    Zombie* horde = zombieHorde(N, "HordeZombie");
    
    if (horde)
    {
        for (int i = 0; i < N; ++i)
        {
            horde[i].announce();
        }
        delete[] horde;
    }
    
    std::cout << "Zombie horde created and announced. Memory cleaned up." << std::endl;
    
    return 0;
}