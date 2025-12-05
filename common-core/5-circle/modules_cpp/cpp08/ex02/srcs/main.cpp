/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:03:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/05 14:43:21 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// int main()
// {
    // std::cout << "=== Test du sujet avec MutantStack ==="<< std::endl;
    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // mstack.push(0);
    
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);

    // std::cout << "\n=== Test équivalent avec std::list ==="<< std::endl;
    // std::list<int> list;
    // list.push_back(5);
    // list.push_back(17);
    // std::cout << list.back() << std::endl;
    // list.pop_back();
    // std::cout << list.size() << std::endl;
    // list.push_back(3);
    // list.push_back(5);
    // list.push_back(737);
    // list.push_back(0);
    
    // std::list<int>::iterator lit = list.begin();
    // std::list<int>::iterator lite = list.end();
    // ++lit;
    // --lit;
    // while (lit != lite)
    // {
    //     std::cout << *lit << std::endl;
    //     ++lit;
    // }

    // std::cout << "\n=== Test avec reverse iterators ==="<< std::endl;
    // MutantStack<int> mstack2;
    // for (int i = 0; i < 5; i++)
    //     mstack2.push(i);
    
    // std::cout << "Forward: ";
    // for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    
    // std::cout << "Reverse: ";
    // for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit)
    //     std::cout << *rit << " ";
    // std::cout << std::endl;

    // std::cout << "\n=== Test copy constructor ==="<< std::endl;
    // MutantStack<int> mstack3;
    // mstack3.push(42);
    // mstack3.push(84);
    // mstack3.push(126);
    
    // MutantStack<int> mstack4(mstack3);
    // std::cout << "Original size: " << mstack3.size() << std::endl;
    // std::cout << "Copy size: " << mstack4.size() << std::endl;
    // std::cout << "Copy content: ";
    // for (MutantStack<int>::iterator it = mstack4.begin(); it != mstack4.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    // std::cout << "\n=== Test avec strings ==="<< std::endl;
    // MutantStack<std::string> strStack;
    // strStack.push("Hello");
    // strStack.push("World");
    // strStack.push("!");
    
    // for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    // return 0;
// }
