/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/11 11:46:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    std::cout << "=== Test des constructeurs ===" << std::endl;
    ClapTrap clap1;
    ClapTrap clap2("Alice");
    ClapTrap clap3("Bob");
    
    std::cout << "\n=== Test du constructeur de copie ===" << std::endl;
    ClapTrap clap4(clap2);
    
    std::cout << "\n=== Test de l'opérateur d'assignation ===" << std::endl;
    ClapTrap clap5;
    clap5 = clap3;

    std::cout << "\n=== Test des attaques de base ===" << std::endl;
    clap2.setAttackDamage(3);
    clap2.attack("Bob");
    clap3.takeDamage(3);

    clap3.setAttackDamage(5);
    clap3.attack("Alice");
    clap2.takeDamage(5);

    std::cout << "\n=== Test des réparations ===" << std::endl;
    clap2.beRepaired(4);
    clap3.beRepaired(2);

    std::cout << "\n=== Test de l'épuisement d'énergie ===" << std::endl;
    ClapTrap energyTest("EnergyTest");
    energyTest.setAttackDamage(1);
    
    // Épuiser l'énergie (10 points initiaux)
    for (int i = 0; i < 12; i++) {
        std::cout << "Action " << (i+1) << ": ";
        if (i % 2 == 0)
            energyTest.attack("Target");
        else
            energyTest.beRepaired(1);
    }

    std::cout << "\n=== Test de la mort d'un ClapTrap ===" << std::endl;
    ClapTrap deathTest("DeathTest");
    deathTest.setAttackDamage(15);
    
    deathTest.attack("Alice");
    clap2.takeDamage(15); // Alice devrait mourir
    
    // Tenter d'attaquer/réparer quand mort
    clap2.attack("Bob");
    clap2.beRepaired(5);
    clap2.takeDamage(5); // Tenter de faire des dégâts à un mort

    std::cout << "\n=== Test de dégâts excessifs ===" << std::endl;
    ClapTrap overDamage("OverDamage");
    overDamage.takeDamage(50); // Plus que les HP max

    std::cout << "\n=== Fin des tests ===" << std::endl;
    return 0;
}
