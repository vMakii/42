/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/16 12:06:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
    std::cout << "----- ANIMAL TESTS -----" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound(); // will output the cat sound!
	dog->makeSound();
	meta->makeSound();
    
    return (0);
}
