/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:53:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/01 11:26:27 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isInt(const std::string& str)
{
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);
    return (*end == '\0' && val >= std::numeric_limits<int>::min() && 
            val <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    
    size_t len = str.length();
    if (len == 0 || str[len - 1] != 'f')
        return false;
    
    char* end;
    std::strtof(str.c_str(), &end);
    return (end == str.c_str() + len - 1 || *end == 'f');
}

static bool isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    
    char* end;
    std::strtod(str.c_str(), &end);
    return (*end == '\0');
}

static void printChar(double value, bool impossible)
{
    std::cout << "char: ";
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < 0 || value > 127)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

static void printInt(double value, bool impossible)
{
    std::cout << "int: ";
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() || 
             value > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

static void printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff");
    else
    {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
    }
    std::cout << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf");
    else
        std::cout << std::fixed << std::setprecision(1) << value;
    std::cout << std::endl;
}

void ScalarConverter::convert(const char* literal)
{
    if (!literal)
    {
        std::cout << "Error: null pointer" << std::endl;
        return;
    }

    std::string str(literal);
    double value = 0;
    bool impossible = false;

    // Detect type and convert
    if (isChar(str))
    {
        value = static_cast<double>(str[0]);
    }
    else if (isInt(str))
    {
        value = static_cast<double>(std::atoi(str.c_str()));
    }
    else if (isFloat(str))
    {
        if (str == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (str == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else
            value = static_cast<double>(std::atof(str.c_str()));
    }
    else if (isDouble(str))
    {
        if (str == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (str == "-inf")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::atof(str.c_str());
    }
    else
    {
        impossible = true;
    }

    // Print conversions
    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value);
    printDouble(value);
}