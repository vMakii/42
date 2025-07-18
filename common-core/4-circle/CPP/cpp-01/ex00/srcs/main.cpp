/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:27:52 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 10:55:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "=== Testing Stack Allocation (randomChump) ===" << std::endl;
    randomChump("StackZombie");
    std::cout << "randomChump function finished - StackZombie should be destroyed\n" << std::endl;
    
    std::cout << "=== Testing Heap Allocation (newZombie) ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << "About to delete " << heapZombie->getName() << " manually" << std::endl;
    delete heapZombie;
    
    std::cout << "\n=== Testing Local Stack Allocation ===" << std::endl;
    {
        Zombie localZombie("gburtin");
        localZombie.announce();
        std::cout << "About to exit scope - " << localZombie.getName() << " will be destroyed automatically" << std::endl;
    }
    std::cout << "Scope exited - zombie should be destroyed\n" << std::endl;
    
    return 0;
}