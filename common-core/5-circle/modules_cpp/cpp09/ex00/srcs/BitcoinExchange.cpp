/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 11:28:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors and Destructor
BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv");
    
    std::string line;
    std::getline(file, line); // Skip header line
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        
        if (std::getline(ss, date, ',') && std::getline(ss, valueStr))
        {
            double value = atof(valueStr.c_str());
            this->data[date] = value;
        }
    }
    
    file.close();
    
    if (this->data.empty())
        throw std::runtime_error("Error: data.csv is empty or invalid");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Getters and Setters
std::map<std::string, double> BitcoinExchange::getData() const
{
    return this->data;
}

// Private Helper Functions
bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    // Check days in month
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    char* end;
    value = strtod(valueStr.c_str(), &end);
    
    if (*end != '\0' && *end != ' ')
        return false;
    
    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = this->data.find(date);
    
    if (it != this->data.end())
        return it->second;
    
    // Find closest lower date
    it = this->data.lower_bound(date);
    if (it == this->data.begin())
        return this->data.begin()->second;
    
    --it;
    return it->second;
}

// Member Functions
void BitcoinExchange::readInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        
        // Parse date | value
        if (!std::getline(ss, date, '|'))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Trim spaces from date
        size_t start = date.find_first_not_of(" \t");
        size_t end = date.find_last_not_of(" \t");
        if (start == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = date.substr(start, end - start + 1);
        
        if (!std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Trim spaces from value
        start = valueStr.find_first_not_of(" \t");
        end = valueStr.find_last_not_of(" \t");
        if (start == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        valueStr = valueStr.substr(start, end - start + 1);
        
        // Validate date
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Validate value
        double value;
        if (!isValidValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Calculate and display result
        double rate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    
    file.close();
}