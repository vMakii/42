/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:51 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 11:22:17 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon
{
    private:
	    std::string type;

    public:
	    Weapon(const std::string &type);
	    ~Weapon();
	    const std::string &getType() const;
	    void setType(const std::string &type);
};