/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/11 17:22:09 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
    std::cout << "===================================================" << std::endl;
    std::cout << "=== TEST COMPLET DE LA CLASSE DIAMONDTRAP ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "\n=== Test des constructeurs DiamondTrap ===" << std::endl;
    DiamondTrap diamond1;
    DiamondTrap diamond2("Sparky");
    
    std::cout << "\n=== Test du constructeur de copie DiamondTrap ===" << std::endl;
    DiamondTrap diamond3(diamond2);
    
    std::cout << "\n=== Test de l'opérateur d'assignation DiamondTrap ===" << std::endl;
    DiamondTrap diamond4;
    diamond4 = diamond2;

    std::cout << "\n=== Test de whoAmI - Fonction unique de DiamondTrap ===" << std::endl;
    diamond2.whoAmI();
    diamond3.whoAmI();
    diamond4.whoAmI();

    std::cout << "\n=== Test des caractéristiques héritées ===" << std::endl;
    std::cout << "DiamondTrap devrait avoir:" << std::endl;
    std::cout << "- HP de FragTrap (100)" << std::endl;
    std::cout << "- Energy Points de ScavTrap (50)" << std::endl;
    std::cout << "- Attack Damage de FragTrap (30)" << std::endl;
    std::cout << "- Attack function de ScavTrap" << std::endl;

    std::cout << "\n=== Test de l'attaque (héritée de ScavTrap) ===" << std::endl;
    diamond2.attack("Enemy");
    diamond2.attack("Another Enemy");

    std::cout << "\n=== Test des fonctions héritées de ClapTrap ===" << std::endl;
    diamond2.takeDamage(25);
    diamond2.beRepaired(15);
    diamond2.takeDamage(10);

    std::cout << "\n=== Test des fonctions spéciales héritées ===" << std::endl;
    std::cout << "Fonction guardGate de ScavTrap:" << std::endl;
    diamond2.guardGate();
    
    std::cout << "Fonction highFivesGuys de FragTrap:" << std::endl;
    diamond2.highFivesGuys();

    std::cout << "\n=== Test d'épuisement d'énergie ===" << std::endl;
    DiamondTrap energyTest("EnergyTester");
    
    // DiamondTrap a 50 points d'énergie (de ScavTrap)
    std::cout << "Test de 6 actions consécutives:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "Action " << (i+1) << ": ";
        if (i % 3 == 0)
            energyTest.attack("Target");
        else if (i % 3 == 1)
            energyTest.beRepaired(5);
        else
            energyTest.guardGate();
    }

    std::cout << "\n=== Test de survie (HP élevés) ===" << std::endl;
    DiamondTrap survivor("Survivor");
    survivor.takeDamage(50);
    survivor.beRepaired(30);
    survivor.takeDamage(60);
    survivor.beRepaired(40);
    survivor.whoAmI();

    std::cout << "\n=== Test de mort ===" << std::endl;
    DiamondTrap mortal("Mortal");
    mortal.takeDamage(150); // Plus que les 100 HP
    
    std::cout << "Tentative d'actions quand mort:" << std::endl;
    mortal.attack("Ghost");
    mortal.beRepaired(20);
    mortal.guardGate();
    mortal.highFivesGuys();
    mortal.whoAmI();

    std::cout << "\n=== Combat DiamondTrap vs autres classes ===" << std::endl;
    DiamondTrap champion("Champion");
    
    {
        std::cout << "Création d'un ClapTrap adversaire:" << std::endl;
        ClapTrap weakling("Weakling");
        champion.attack("Weakling");
        weakling.takeDamage(30); // ClapTrap a seulement 10 HP
    }
    
    {
        std::cout << "Création d'un ScavTrap adversaire:" << std::endl;
        ScavTrap guardian("Guardian");
        champion.attack("Guardian");
        guardian.takeDamage(30);
        guardian.attack("Champion");
        champion.takeDamage(20);
    }
    
    {
        std::cout << "Création d'un FragTrap adversaire:" << std::endl;
        FragTrap demolisher("Demolisher");
        champion.attack("Demolisher");
        demolisher.takeDamage(30);
        demolisher.attack("Champion");
        champion.takeDamage(30);
    }

    std::cout << "\n=== DiamondTrap vs DiamondTrap ===" << std::endl;
    DiamondTrap fighter1("Alpha");
    DiamondTrap fighter2("Beta");
    
    fighter1.whoAmI();
    fighter2.whoAmI();
    
    fighter1.attack("Beta");
    fighter2.takeDamage(30);
    
    fighter2.attack("Alpha");
    fighter1.takeDamage(30);
    
    fighter1.whoAmI();
    fighter2.whoAmI();

    std::cout << "\n=== Résumé des caractéristiques finales ===" << std::endl;
    std::cout << "ClapTrap: 10 HP, 10 Energy, 0 Attack Damage" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack Damage + guardGate()" << std::endl;
    std::cout << "FragTrap: 100 HP, 100 Energy, 30 Attack Damage + highFivesGuys()" << std::endl;
    std::cout << "DiamondTrap: 100 HP, 50 Energy, 30 Attack Damage" << std::endl;
    std::cout << "             + ScavTrap::attack() + guardGate() + highFivesGuys() + whoAmI()" << std::endl;

    std::cout << "\n=== Test des destructeurs (ordre Diamond Problem) ===" << std::endl;
    std::cout << "Fin du programme, destruction automatique des objets..." << std::endl;
    std::cout << "Ordre attendu: ~DiamondTrap -> ~FragTrap -> ~ScavTrap -> ~ClapTrap" << std::endl;
    
    return 0;
}
