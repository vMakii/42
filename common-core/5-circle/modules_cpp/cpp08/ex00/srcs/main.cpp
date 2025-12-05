/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:03:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/05 11:01:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    // Test avec un vector
    std::cout << "=== Test avec std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Test avec une list
    std::cout << "\n=== Test avec std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    // Test avec une deque
    std::cout << "\n=== Test avec std::deque ===" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    try {
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 150);
        std::cout << "Trouvé: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}