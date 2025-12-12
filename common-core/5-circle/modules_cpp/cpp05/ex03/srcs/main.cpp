/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/12 14:13:10 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void printSeparator(const std::string& title)
{
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << title << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

int main()
{
    // Initialize random seed for RobotomyRequestForm
    std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    
    // ========== TEST 1: Intern creates Shrubbery Creation Form ==========
    printSeparator("TEST 1: Intern creates Shrubbery Creation Form");
    try
    {
        AForm* form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 2: Intern creates Robotomy Request Form ==========
    printSeparator("TEST 2: Intern creates Robotomy Request Form");
    try
    {
        AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 3: Intern creates Presidential Pardon Form ==========
    printSeparator("TEST 3: Intern creates Presidential Pardon Form");
    try
    {
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 4: Unknown form name ==========
    printSeparator("TEST 4: Intern tries to create unknown form");
    try
    {
        AForm* form = someRandomIntern.makeForm("coffee request", "Espresso");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 5: Case variations ==========
    printSeparator("TEST 5: Testing case insensitivity");
    try
    {
        AForm* form1 = someRandomIntern.makeForm("SHRUBBERY CREATION", "garden");
        AForm* form2 = someRandomIntern.makeForm("RoBoToMy ReQuEsT", "R2-D2");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        
        if (form1)
        {
            std::cout << *form1 << std::endl;
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        
        if (form2)
        {
            std::cout << "\n" << *form2 << std::endl;
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        
        if (form3)
        {
            std::cout << "\n" << *form3 << std::endl;
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 6: Intern creates forms for low-grade bureaucrat ==========
    printSeparator("TEST 6: Low-grade bureaucrat tries forms created by intern");
    try
    {
        Bureaucrat intern("Intern", 145);
        std::cout << intern << std::endl;
        
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "office");
        if (shrubForm)
        {
            std::cout << "\n" << *shrubForm << std::endl;
            intern.signForm(*shrubForm);
            intern.executeForm(*shrubForm);
            delete shrubForm;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ========== TEST 7: Multiple forms from same intern ==========
    printSeparator("TEST 7: Intern creates multiple forms in a row");
    try
    {
        AForm* forms[3];
        forms[0] = someRandomIntern.makeForm("shrubbery creation", "park");
        forms[1] = someRandomIntern.makeForm("robotomy request", "Marvin");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Trillian");
        
        std::cout << "\n--- All forms created, now processing ---" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << "\n" << *forms[i] << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    return 0;
}
