/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:30:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/15 10:48:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string toupperStr(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
			str.at(i) += ('A' - 'a');
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			std::cout << toupperStr(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}