/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:44:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/11/28 15:49:38 by mivogel          ###   ########.fr       */
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
        this->target = other.target;
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
    static int attempt = 0;
    attempt++;
    if (attempt % 2 == 1)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << target << " has failed." << std::endl;
    }
}