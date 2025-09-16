/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:20:27 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 12:22:18 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
        
    public:
        // Constructors and Destructor
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        // Getter and Setters
        void setIdea(int index, const std::string& idea);

        // Member functions
        std::string getIdea(int index) const;
};