/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:41:04 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/24 15:32:36 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
        
    public:
        // Constructors and Destructor
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const std::string& name);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Getters and Setters
        const std::string& getName() const;
        int getGrade() const;

        // Member Functions
        void incrementGrade();
        void decrementGrade();
        void signForm(class Form& form) const;

        // Exception Classes
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);