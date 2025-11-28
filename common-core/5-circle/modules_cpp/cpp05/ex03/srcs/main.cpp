/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/11/28 17:34:58 by mivogel          ###   ########.fr       */
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
    printSeparator("TEST 1: Intern creates ShrubberyCreationForm");
    try
    {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat boss("Boss", 1);
            boss.signForm(*form);
            boss.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 2: Intern creates RobotomyRequestForm");
    try
    {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat engineer("Engineer", 40);
            engineer.signForm(*form);
            engineer.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 3: Intern creates PresidentialPardonForm");
    try
    {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 4: Intern tries to create unknown form");
    try
    {
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("unknown form", "target");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 5: Intern creates multiple forms");
    try
    {
        Intern intern;
        Bureaucrat supreme("Supreme Chief", 1);
        AForm* forms[3];
        
        std::cout << "--- Creating forms ---" << std::endl;
        forms[0] = intern.makeForm("shrubbery creation", "garden");
        forms[1] = intern.makeForm("robotomy request", "R2-D2");
        forms[2] = intern.makeForm("presidential pardon", "Ford Prefect");
        
        std::cout << "\n--- Signing and executing all forms ---" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << "\n" << *forms[i] << std::endl;
                supreme.signForm(*forms[i]);
                supreme.executeForm(*forms[i]);
            }
        }
        
        std::cout << "\n--- Cleaning up ---" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            delete forms[i];
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 6: Testing with wrong case and spacing");
    try
    {
        Intern intern;
        AForm* form1;
        AForm* form2;
        AForm* form3;
        
        std::cout << "--- Trying 'Shrubbery Creation' (wrong case) ---" << std::endl;
        form1 = intern.makeForm("Shrubbery Creation", "test1");
        if (form1)
        {
            std::cout << "Form created: " << form1->getName() << std::endl;
            delete form1;
        }
        
        std::cout << "\n--- Trying 'ROBOTOMY REQUEST' (uppercase) ---" << std::endl;
        form2 = intern.makeForm("ROBOTOMY REQUEST", "test2");
        if (form2)
        {
            std::cout << "Form created: " << form2->getName() << std::endl;
            delete form2;
        }
        
        std::cout << "\n--- Trying 'presidential  pardon' (extra space) ---" << std::endl;
        form3 = intern.makeForm("presidential  pardon", "test3");
        if (form3)
        {
            std::cout << "Form created: " << form3->getName() << std::endl;
            delete form3;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 7: Intern copy and assignment");
    try
    {
        Intern intern1;
        Intern intern2(intern1);  // Copy constructor
        Intern intern3;
        intern3 = intern2;        // Assignment operator
        
        std::cout << "Creating forms with different intern instances..." << std::endl;
        
        AForm* f1 = intern1.makeForm("shrubbery creation", "by_intern1");
        AForm* f2 = intern2.makeForm("robotomy request", "by_intern2");
        AForm* f3 = intern3.makeForm("presidential pardon", "by_intern3");
        
        if (f1)
        {
            std::cout << "Intern1 created: " << f1->getName() << std::endl;
            delete f1;
        }
        if (f2)
        {
            std::cout << "Intern2 created: " << f2->getName() << std::endl;
            delete f2;
        }
        if (f3)
        {
            std::cout << "Intern3 created: " << f3->getName() << std::endl;
            delete f3;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    return 0;
}
