/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:28:01 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/18 11:52:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>


class Zombie 
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void announce() const;
        std::string getName() const;
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);