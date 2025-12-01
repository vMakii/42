/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/01 13:58:09 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    srand(time(NULL));

    Base base;

    std::cout << "=== Test 1: Generate and identify with pointer ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = base.generate();
        std::cout << "Generated type (pointer): ";
        base.identify(ptr);
        delete ptr;
    }

    std::cout << "\n=== Test 2: Generate and identify with reference ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = base.generate();
        std::cout << "Generated type (reference): ";
        base.identify(*ptr);
        delete ptr;
    }

    std::cout << "\n=== Test 3: Test specific types ===" << std::endl;
    A a;
    B b;
    C c;

    std::cout << "Type A (pointer): ";
    base.identify(&a);
    std::cout << "Type A (reference): ";
    base.identify(a);

    std::cout << "Type B (pointer): ";
    base.identify(&b);
    std::cout << "Type B (reference): ";
    base.identify(b);

    std::cout << "Type C (pointer): ";
    base.identify(&c);
    std::cout << "Type C (reference): ";
    base.identify(c);

    return 0;
}
