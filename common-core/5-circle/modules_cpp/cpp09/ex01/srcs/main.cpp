/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:13:16 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 12:00:23 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
        return 1;
    }
    
    try
    {
        RPN rpn;
        rpn.evaluate(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}