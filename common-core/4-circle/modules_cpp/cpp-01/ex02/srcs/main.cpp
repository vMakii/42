/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:59:07 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 11:10:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address of string:             " << &string << std::endl;
    std::cout << "Address held by stringPTR:     " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:     " << &stringREF << std::endl << std::endl;

    std::cout << "Value of string:               " << string << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}