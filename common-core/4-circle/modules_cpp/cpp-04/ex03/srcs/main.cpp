/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:19:05 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/20 12:49:33 by mivogel          ###   ########.fr       */
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

    // Equip the materias
    me->equip(iceMat);
    me->equip(cureMat);

    // Use them
    me->use(0, *bob);
    me->use(1, *bob);

    // Unequip both materias. According to the modified Character::unequip,
    // unequip does NOT delete the materia. Ownership remains with caller.
    me->unequip(0);
    me->unequip(1);

    // Manually delete the unequipped materias to avoid memory leaks
    delete iceMat;
    delete cureMat;

    // Clean up
    delete bob;
    delete me;
    delete src;

    return 0;
}

// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e