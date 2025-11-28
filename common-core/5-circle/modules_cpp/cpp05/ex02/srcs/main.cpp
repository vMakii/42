/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/11/28 16:31:29 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printSeparator(const std::string& title)
{
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << title << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

int main()
{
    // ========== SHRUBBERY CREATION FORM ==========
    // Grade to sign: 145, Grade to execute: 137
    
    printSeparator("TEST 1: ShrubberyCreationForm - Valid execution");
    try
    {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << gardener << std::endl;
        std::cout << shrub << std::endl;
        
        std::cout << "\n--- Signing the form ---" << std::endl;
        gardener.signForm(shrub);
        
        std::cout << "\n--- Executing the form ---" << std::endl;
        gardener.executeForm(shrub);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 2: ShrubberyCreationForm - Not signed");
    try
    {
        Bureaucrat worker("Worker", 100);
        ShrubberyCreationForm shrub("garden");
        
        std::cout << worker << std::endl;
        std::cout << shrub << std::endl;
        
        std::cout << "\n--- Trying to execute without signing ---" << std::endl;
        worker.executeForm(shrub);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 3: ShrubberyCreationForm - Grade too low to execute");
    try
    {
        Bureaucrat boss("Boss", 130);
        Bureaucrat intern("Intern", 140);
        ShrubberyCreationForm shrub("office");
        
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << shrub << std::endl;
        
        std::cout << "\n--- Boss signs the form ---" << std::endl;
        boss.signForm(shrub);
        
        std::cout << "\n--- Intern tries to execute (grade 140 < 137 required) ---" << std::endl;
        intern.executeForm(shrub);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== ROBOTOMY REQUEST FORM ==========
    // Grade to sign: 72, Grade to execute: 45
    
    printSeparator("TEST 4: RobotomyRequestForm - Valid execution");
    try
    {
        Bureaucrat engineer("Engineer", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << engineer << std::endl;
        std::cout << robot << std::endl;
        
        std::cout << "\n--- Signing the form ---" << std::endl;
        engineer.signForm(robot);
        
        std::cout << "\n--- Executing the form ---" << std::endl;
        engineer.executeForm(robot);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 5: RobotomyRequestForm - Grade too low to sign");
    try
    {
        Bureaucrat assistant("Assistant", 80);
        RobotomyRequestForm robot("C-3PO");
        
        std::cout << assistant << std::endl;
        std::cout << robot << std::endl;
        
        std::cout << "\n--- Trying to sign (grade 80 < 72 required) ---" << std::endl;
        assistant.signForm(robot);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 6: RobotomyRequestForm - Grade too low to execute");
    try
    {
        Bureaucrat signer("Signer", 70);
        Bureaucrat executor("Executor", 50);
        RobotomyRequestForm robot("R2-D2");
        
        std::cout << signer << std::endl;
        std::cout << executor << std::endl;
        std::cout << robot << std::endl;
        
        std::cout << "\n--- Signer signs the form ---" << std::endl;
        signer.signForm(robot);
        
        std::cout << "\n--- Executor tries to execute (grade 50 < 45 required) ---" << std::endl;
        executor.executeForm(robot);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== PRESIDENTIAL PARDON FORM ==========
    // Grade to sign: 25, Grade to execute: 5
    
    printSeparator("TEST 7: PresidentialPardonForm - Valid execution");
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- Signing the form ---" << std::endl;
        president.signForm(pardon);
        
        std::cout << "\n--- Executing the form ---" << std::endl;
        president.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 8: PresidentialPardonForm - Grade too low to sign");
    try
    {
        Bureaucrat manager("Manager", 30);
        PresidentialPardonForm pardon("Ford Prefect");
        
        std::cout << manager << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- Trying to sign (grade 30 < 25 required) ---" << std::endl;
        manager.signForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 9: PresidentialPardonForm - Grade too low to execute");
    try
    {
        Bureaucrat topManager("TopManager", 20);
        Bureaucrat vicePresident("VicePresident", 10);
        PresidentialPardonForm pardon("Zaphod Beeblebrox");
        
        std::cout << topManager << std::endl;
        std::cout << vicePresident << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- TopManager signs the form ---" << std::endl;
        topManager.signForm(pardon);
        
        std::cout << "\n--- VicePresident tries to execute (grade 10 < 5 required) ---" << std::endl;
        vicePresident.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== BONUS: Multiple forms execution ==========
    
    printSeparator("TEST 10: High-level bureaucrat executes all forms");
    try
    {
        Bureaucrat supreme("Supreme Chief", 1);
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Trillian");
        
        std::cout << supreme << std::endl;
        std::cout << "\n--- Signing all forms ---" << std::endl;
        supreme.signForm(shrub);
        supreme.signForm(robot);
        supreme.signForm(pardon);
        
        std::cout << "\n--- Executing all forms ---" << std::endl;
        supreme.executeForm(shrub);
        supreme.executeForm(robot);
        supreme.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    return 0;
}
