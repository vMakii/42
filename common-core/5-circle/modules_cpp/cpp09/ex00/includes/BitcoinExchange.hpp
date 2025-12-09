/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:55:02 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 11:28:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr, double& value) const;
        double getExchangeRate(const std::string& date) const;
    public:
        // Constructors and Destructor
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        // Getters and Setters
        std::map<std::string, double> getData() const;
        // Member Functions
        // void loadData(const std::string& filename);
        void readInput(const std::string& filename);
};