/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:19:05 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/24 13:37:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    // Create a materia source and teach it two materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create a character "me" and another character "bob"
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // Create materias from the source. We keep the returned pointers so
    // we can delete them manually after unequipping to avoid leaks.
    AMateria* iceMat = src->createMateria("ice");
    AMateria* cureMat = src->createMateria("cure");

    // Equip the materias on original character FIRST
    me->equip(iceMat);
    me->equip(cureMat);
    
    // NOW create a deep copy of the equipped character
    Character* tmp = new Character(*(static_cast<Character*>(me)));

    // Use them with original character
    std::cout << "=== Using materias with original character 'me' ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    // Use them with copied character (should work because of deep copy)
    std::cout << "=== Using materias with copied character 'tmp' ===" << std::endl;
    tmp->use(0, *bob);
    tmp->use(1, *bob);
    
    // Unequip from original - tmp should still have its own copies
    std::cout << "=== After unequipping from original 'me' ===" << std::endl;
    me->unequip(0);
    me->unequip(1);
    
    // tmp should still be able to use its materias (proof of deep copy)
    std::cout << "=== tmp can still use its materias (deep copy proof) ===" << std::endl;
    tmp->use(0, *bob);
    tmp->use(1, *bob);

    // Manually delete the unequipped materias to avoid memory leaks
    delete iceMat;
    delete cureMat;

    // Clean up
    delete bob;
    delete me;
    delete tmp;  // Don't forget to delete the copied character
    delete src;

    return 0;
}

// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e