/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:44:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/12 13:54:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and Destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        // target is const and cannot be reassigned
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Getters
const std::string& RobotomyRequestForm::getTarget() const
{
    return target;
}

// Member Functions
void RobotomyRequestForm::doExecute() const
{
    std::cout << "Bzzzzzz... Vrrrrrr... *drilling noises*" << std::endl;
    // 50% chance of success
    int randomValue = std::rand();
    // std::cout << "Random value: " << randomValue << std::endl; // Debug line to see the random value
    if (randomValue % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
    }
}