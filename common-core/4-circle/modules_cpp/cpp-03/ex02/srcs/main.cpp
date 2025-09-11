/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/11 16:29:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    std::cout << "=== Test des constructeurs ClapTrap ===" << std::endl;
    ClapTrap clap1;
    ClapTrap clap2("Alice");
    
    std::cout << "\n=== Test des constructeurs ScavTrap ===" << std::endl;
    ScavTrap scav1;
    ScavTrap scav2("Guardian");
    
    std::cout << "\n=== Test des constructeurs FragTrap ===" << std::endl;
    FragTrap frag1;
    FragTrap frag2("Demolisher");
    FragTrap frag3("Bomber");
    
    std::cout << "\n=== Test du constructeur de copie FragTrap ===" << std::endl;
    FragTrap frag4(frag2);
    
    std::cout << "\n=== Test de l'opérateur d'assignation FragTrap ===" << std::endl;
    FragTrap frag5;
    frag5 = frag3;

    std::cout << "\n=== Test des attaques - Comparaison des 3 classes ===" << std::endl;
    std::cout << "ClapTrap (10 HP, 10 Energy, 0 Attack):" << std::endl;
    clap2.attack("Target");
    
    std::cout << "ScavTrap (100 HP, 50 Energy, 20 Attack):" << std::endl;
    scav2.attack("Target");
    
    std::cout << "FragTrap (100 HP, 100 Energy, 30 Attack):" << std::endl;
    frag2.attack("Target");

    std::cout << "\n=== Test des dégâts et réparations ===" << std::endl;
    std::cout << "FragTrap prend des dégâts:" << std::endl;
    frag2.takeDamage(25);
    frag2.beRepaired(15);
    
    std::cout << "ScavTrap prend des dégâts:" << std::endl;
    scav2.takeDamage(30);
    scav2.beRepaired(20);

    std::cout << "\n=== Test des fonctions spéciales ===" << std::endl;
    std::cout << "ScavTrap - Gate Keeper mode:" << std::endl;
    scav2.guardGate();
    scav2.guardGate(); // Test si déjà en mode garde
    
    std::cout << "FragTrap - High Five:" << std::endl;
    frag2.highFivesGuys();
    frag3.highFivesGuys();

    std::cout << "\n=== Test d'épuisement d'énergie FragTrap ===" << std::endl;
    FragTrap energyTest("EnergyTest");
    
    // FragTrap a 100 points d'énergie, testons plusieurs actions
    for (int i = 0; i < 8; i++) {
        std::cout << "Action " << (i+1) << ": ";
        if (i % 4 == 0)
            energyTest.attack("Target");
        else if (i % 4 == 1)
            energyTest.beRepaired(5);
        else if (i % 4 == 2)
            energyTest.highFivesGuys();
        else
            energyTest.attack("Another Target");
    }

    std::cout << "\n=== Test de la mort d'un FragTrap ===" << std::endl;
    FragTrap deathTest("DeathTest");
    deathTest.takeDamage(150); // Plus que les 100 HP max
    
    // Tenter d'utiliser les fonctions quand mort
    deathTest.attack("Someone");
    deathTest.beRepaired(10);
    deathTest.highFivesGuys();

    std::cout << "\n=== Combat entre les classes ===" << std::endl;
    FragTrap fighter1("Destroyer");
    ScavTrap fighter2("Protector");
    ClapTrap fighter3("Underdog");
    
    std::cout << "FragTrap vs ScavTrap:" << std::endl;
    fighter1.attack("Protector");
    fighter2.takeDamage(30);
    
    fighter2.attack("Destroyer");
    fighter1.takeDamage(20);
    
    std::cout << "FragTrap vs ClapTrap:" << std::endl;
    fighter1.attack("Underdog");
    fighter3.takeDamage(30); // ClapTrap n'a que 10 HP, il va mourir
    
    fighter3.attack("Destroyer"); // Ne devrait pas marcher car mort

    std::cout << "\n=== Résumé des caractéristiques ===" << std::endl;
    std::cout << "ClapTrap: 10 HP, 10 Energy, 0 Attack Damage" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack Damage + Gate Keeper" << std::endl;
    std::cout << "FragTrap: 100 HP, 100 Energy, 30 Attack Damage + High Five" << std::endl;

    std::cout << "\n=== Test des destructeurs (ordre d'appel) ===" << std::endl;
    std::cout << "Fin du programme, destruction automatique des objets..." << std::endl;
    
    return 0;
}
