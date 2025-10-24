/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:04:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/24 15:47:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm 
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

    public:
        // Constructors and Destructor
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Member Functions
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);