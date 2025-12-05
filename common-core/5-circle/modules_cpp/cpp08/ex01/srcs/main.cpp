/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:03:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/05 12:19:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "=== Test du sujet ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n=== Test avec addNumber itérateurs ===" << std::endl;
    try {
        Span sp2 = Span(10);
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(5);
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);
        
        sp2.addNumber(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test avec 10000 nombres ===" << std::endl;
    try {
        Span sp3 = Span(10000);
        std::vector<int> largeNumbers;
        for (int i = 0; i < 10000; i++) {
            largeNumbers.push_back(i * 2);
        }
        sp3.addNumber(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test exception: pas assez de nombres ===" << std::endl;
    try {
        Span sp4 = Span(5);
        sp4.addNumber(42);
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test exception: span plein ===" << std::endl;
    try {
        Span sp5 = Span(3);
        std::vector<int> tooMany;
        tooMany.push_back(1);
        tooMany.push_back(2);
        tooMany.push_back(3);
        tooMany.push_back(4);
        sp5.addNumber(tooMany.begin(), tooMany.end());
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test avec nombres négatifs ===" << std::endl;
    try {
        Span sp6 = Span(5);
        sp6.addNumber(-10);
        sp6.addNumber(-5);
        sp6.addNumber(0);
        sp6.addNumber(5);
        sp6.addNumber(10);
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}