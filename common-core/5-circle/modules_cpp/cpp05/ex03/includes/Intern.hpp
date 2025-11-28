/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:03:50 by mivogel           #+#    #+#             */
/*   Updated: 2025/11/28 17:13:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
    public:
        // Constructors and Destructor
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Member Functions
        AForm* makeForm(const std::string& formName, const std::string& target) const;

        // Exception Classes
        class UnknownFormException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};