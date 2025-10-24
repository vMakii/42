/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/24 15:32:36 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: Creation of valid Forms ===" << std::endl;
    try
    {
        Form formA("Tax Form", 50, 25);
        std::cout << formA << std::endl;
        
        Form formB("Contract", 10, 5);
        std::cout << formB << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 2: Invalid Form creation (grade too high) ===" << std::endl;
    try
    {
        Form invalidForm("Invalid", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 3: Invalid Form creation (grade too low) ===" << std::endl;
    try
    {
        Form invalidForm("Invalid", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 4: Bureaucrat signs a Form (success) ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 30);
        Form formC("Budget Approval", 50, 25);
        
        std::cout << bob << std::endl;
        std::cout << formC << std::endl;
        
        bob.signForm(formC);
        std::cout << "After signing: " << formC << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 5: Bureaucrat cannot sign Form (grade too low) ===" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 100);
        Form importantForm("Executive Order", 20, 10);
        
        std::cout << intern << std::endl;
        std::cout << importantForm << std::endl;
        
        intern.signForm(importantForm);
        std::cout << "After signing: " << importantForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 6: Multiple Bureaucrats signing different Forms ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat charlie("Charlie", 75);
        
        Form form1("Form A", 10, 5);
        Form form2("Form B", 80, 60);
        Form form3("Form C", 50, 30);
        
        std::cout << "--- Alice (grade 1) ---" << std::endl;
        alice.signForm(form1);
        alice.signForm(form2);
        alice.signForm(form3);
        
        std::cout << "\n--- Charlie (grade 75) ---" << std::endl;
        charlie.signForm(form1);
        charlie.signForm(form2);
        charlie.signForm(form3);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 7: Bureaucrat grade changes affect signing ability ===" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 51);
        Form specialForm("Special Form", 50, 30);
        
        std::cout << dave << std::endl;
        std::cout << specialForm << std::endl;
        
        std::cout << "Attempting to sign with grade 51..." << std::endl;
        dave.signForm(specialForm);
        
        std::cout << "\nIncrementing Dave's grade..." << std::endl;
        dave.incrementGrade();
        std::cout << dave << std::endl;
        
        std::cout << "Attempting to sign with grade 50..." << std::endl;
        dave.signForm(specialForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== TEST 8: Copy constructor and assignment operator ===" << std::endl;
    try
    {
        Form original("Original Form", 40, 20);
        Bureaucrat signer("Signer", 30);
        
        signer.signForm(original);
        std::cout << "Original: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Form assigned("Temp", 100, 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
