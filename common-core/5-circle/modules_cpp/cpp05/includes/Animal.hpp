/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:19:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 11:33:30 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal 
{
    protected:
        std::string type;
    
    public:
    // Constructors and Destructor
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        // Getters and Setters
        std::string getType() const;

        // Member functions
        virtual void makeSound() const;
};