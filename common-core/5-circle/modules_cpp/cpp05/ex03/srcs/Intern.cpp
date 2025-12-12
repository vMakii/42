/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:12:49 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/12 14:12:56 by mivogel          ###   ########.fr       */
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

// Helper function to convert string to lowercase
static std::string toLowerString(const std::string& str)
{
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i)
    {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

// Member Functions
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    std::string normalizedFormName = toLowerString(formName);
    std::cout << "Intern: normalized form name is \"" << normalizedFormName << "\"" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        if (normalizedFormName == formNames[i])
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
