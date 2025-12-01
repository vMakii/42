/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:41:47 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/01 13:57:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base *Base::generate(void)
{
    int randNum = rand() % 3;

    switch (randNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        A& aRef = dynamic_cast<A&>(p);
        (void)aRef;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        B& bRef = dynamic_cast<B&>(p);
        (void)bRef;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& cRef = dynamic_cast<C&>(p);
        (void)cRef;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown Type" << std::endl;
}