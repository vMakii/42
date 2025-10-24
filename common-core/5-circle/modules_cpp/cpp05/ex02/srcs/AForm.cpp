/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:17:04 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/24 15:55:30 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and Destructor
AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // name, gradeToSign and gradeToExecute are const and cannot be assigned
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// Getters and Setters
const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

// Member Functions
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception Classes
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}