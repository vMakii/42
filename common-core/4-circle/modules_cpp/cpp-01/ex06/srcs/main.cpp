/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:46 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/01 17:15:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return (EXIT_FAILURE);
    }

    Harl harl;
    harl.complain(argv[1]);
    
    return (EXIT_SUCCESS);
}