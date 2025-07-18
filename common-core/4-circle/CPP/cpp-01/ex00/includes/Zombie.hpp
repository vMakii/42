/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:06:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 10:50:26 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie 
{
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce() const;
        std::string getName() const;
};

// Function prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);