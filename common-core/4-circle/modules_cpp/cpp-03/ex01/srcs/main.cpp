/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/11 13:15:54 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    std::cout << "=== Test des constructeurs ClapTrap ===" << std::endl;
    ClapTrap clap1;
    ClapTrap clap2("Alice");
    
    std::cout << "\n=== Test des constructeurs ScavTrap ===" << std::endl;
    ScavTrap scav1;
    ScavTrap scav2("Guardian");
    ScavTrap scav3("Warrior");
    
    std::cout << "\n=== Test du constructeur de copie ScavTrap ===" << std::endl;
    ScavTrap scav4(scav2);
    
    std::cout << "\n=== Test de l'opérateur d'assignation ScavTrap ===" << std::endl;
    ScavTrap scav5;
    scav5 = scav3;

    std::cout << "\n=== Test des attaques ScavTrap vs ClapTrap ===" << std::endl;
    scav2.attack("Alice");
    clap2.takeDamage(20);
    
    clap2.attack("Guardian");
    scav2.takeDamage(0); // ClapTrap fait 0 dégâts par défaut

    std::cout << "\n=== Test des réparations ===" << std::endl;
    clap2.beRepaired(4);
    scav2.beRepaired(10);

    std::cout << "\n=== Test de la fonction spéciale guardGate ===" << std::endl;
    scav2.guardGate();
    scav3.guardGate();

    std::cout << "\n=== Test de l'épuisement d'énergie ScavTrap ===" << std::endl;
    ScavTrap energyTest("EnergyTest");
    
    // ScavTrap a 50 points d'énergie, testons quelques actions
    for (int i = 0; i < 5; i++) {
        std::cout << "Action " << (i+1) << ": ";
        if (i % 3 == 0)
            energyTest.attack("Target");
        else if (i % 3 == 1)
            energyTest.beRepaired(5);
        else
            energyTest.guardGate();
    }

    std::cout << "\n=== Test de la mort d'un ScavTrap ===" << std::endl;
    ScavTrap deathTest("DeathTest");
    deathTest.takeDamage(150); // Plus que les 100 HP max de ScavTrap
    
    // Tenter d'attaquer/réparer/garder quand mort
    deathTest.attack("Someone");
    deathTest.beRepaired(5);
    deathTest.guardGate();

    std::cout << "\n=== Test des différences entre ClapTrap et ScavTrap ===" << std::endl;
    std::cout << "ClapTrap: 10 HP, 10 Energy, 0 Attack Damage" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack Damage" << std::endl;
    
    ClapTrap weakling("Weakling");
    ScavTrap strong("Strong");
    
    weakling.attack("Strong");
    strong.takeDamage(0);
    
    strong.attack("Weakling");
    weakling.takeDamage(20);

    std::cout << "\n=== Fin des tests ===" << std::endl;
    return 0;
}
