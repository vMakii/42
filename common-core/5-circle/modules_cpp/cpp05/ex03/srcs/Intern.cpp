/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:12:49 by mivogel           #+#    #+#             */
/*   Updated: 2025/11/28 17:31:09 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors and Destructor
Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

// Member Functions
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::string formNames[3] = {
        "Shrubbery Creation",
        "Robotomy Request",
        "Presidential Pardon"
    };
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            switch (i)
            {
                case 0:
                    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
                    return new ShrubberyCreationForm(target);
                case 1:
                    std::cout << "Intern creates Robotomy Request Form" << std::endl;
                    return new RobotomyRequestForm(target);
                case 2:
                    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
                    return new PresidentialPardonForm(target);
            }
        }
    }
    throw UnknownFormException();
}

// Exception Classes
const char* Intern::UnknownFormException::what() const throw()
{
    return "Intern: Unknown form name";
}
