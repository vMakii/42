/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:03:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/02 15:25:03 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Fonction qui prend une référence non-const (modifie l'élément)
template <typename T>
void increment(T& x)
{
    x++;
}

// Fonction qui prend une référence const (lecture seule)
template <typename T>
void printElement(T const& x)
{
    std::cout << x << " ";
}

// Fonction spécialisée pour les strings
void toUpper(std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        str[i] = std::toupper(str[i]);
    }
}

int main()
{
    std::cout << "=== Test avec des int ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = 5;
    
    std::cout << "Avant increment: ";
    ::iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    ::iter(intArray, intSize, increment<int>);
    
    std::cout << "Après increment: ";
    ::iter(intArray, intSize, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test avec des double ===" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = 4;
    
    std::cout << "Avant increment: ";
    ::iter(doubleArray, doubleSize, printElement<double>);
    std::cout << std::endl;
    
    ::iter(doubleArray, doubleSize, increment<double>);
    
    std::cout << "Après increment: ";
    ::iter(doubleArray, doubleSize, printElement<double>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test avec des string ===" << std::endl;
    std::string strArray[] = {"hello", "world", "cpp", "templates"};
    size_t strSize = 4;
    
    std::cout << "Avant toUpper: ";
    ::iter(strArray, strSize, printElement<std::string>);
    std::cout << std::endl;
    
    ::iter(strArray, strSize, toUpper);
    
    std::cout << "Après toUpper: ";
    ::iter(strArray, strSize, printElement<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test avec des char ===" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charSize = 5;
    
    std::cout << "Affichage: ";
    ::iter(charArray, charSize, printElement<char>);
    std::cout << std::endl;
    
    return 0;
}