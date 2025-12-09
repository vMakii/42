/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:13:16 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 13:37:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << av[0] << " [positive integers]" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe sorter;
        sorter.parseInput(ac, av);
        sorter.sortAndDisplay();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`