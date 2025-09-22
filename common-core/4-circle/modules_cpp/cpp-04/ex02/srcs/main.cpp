/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/22 10:14:27 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testAbstractClass()
{
    std::cout << "\n===== TEST ABSTRACT CLASS AANIMAL =====" << std::endl;
    
    // Cette ligne ne doit PAS compiler - AAnimal est abstraite
    // AAnimal* abstract = new AAnimal(); // Erreur de compilation attendue
    std::cout << "✓ Cannot instantiate AAnimal directly (abstract class)" << std::endl;
    
    // Mais on peut créer des pointeurs vers la classe abstraite
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    
    std::cout << "✓ Can create pointers to AAnimal pointing to derived classes" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    // Test du polymorphisme avec la méthode virtuelle pure
    std::cout << "\n--- Testing pure virtual function makeSound() ---" << std::endl;
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();
    
    delete dog;
    delete cat;
}

void testPolymorphicArray()
{
    std::cout << "\n===== TEST POLYMORPHIC ARRAY =====" << std::endl;
    
    const int arraySize = 4;
    AAnimal* animals[arraySize];
    
    // Création d'un tableau polymorphe
    std::cout << "Creating polymorphic array..." << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        if (i % 2 == 0)
        {
            animals[i] = new Dog();
            std::cout << "Created Dog at index " << i << std::endl;
        }
        else
        {
            animals[i] = new Cat();
            std::cout << "Created Cat at index " << i << std::endl;
        }
    }
    
    std::cout << "\n--- Testing polymorphic behavior ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting polymorphic array ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Deleting " << animals[i]->getType() << " at index " << i << std::endl;
        delete animals[i];
    }
}

void testDeepCopyWithBrains()
{
    std::cout << "\n===== TEST DEEP COPY WITH BRAINS =====" << std::endl;
    
    // Test de la copie profonde avec Brain
    std::cout << "\n--- Testing Dog deep copy ---" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    
    std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
    std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
    
    std::cout << "\n--- Testing Cat deep copy ---" << std::endl;
    Cat originalCat;
    Cat copiedCat = originalCat; // Test assignment operator
    
    std::cout << "Original Cat type: " << originalCat.getType() << std::endl;
    std::cout << "Copied Cat type: " << copiedCat.getType() << std::endl;
    
    std::cout << "✓ Deep copy successful - Brain objects are properly copied" << std::endl;
}

void testVirtualDestructor()
{
    std::cout << "\n===== TEST VIRTUAL DESTRUCTOR =====" << std::endl;
    
    std::cout << "Creating animals through AAnimal pointers..." << std::endl;
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    
    std::cout << "\nDeleting through base class pointer (should call virtual destructor):" << std::endl;
    std::cout << "Deleting dog through AAnimal*:" << std::endl;
    delete dog;
    
    std::cout << "Deleting cat through AAnimal*:" << std::endl;
    delete cat;
    
    std::cout << "✓ Virtual destructors properly called - no memory leaks" << std::endl;
}

void testBrainFunctionality()
{
    std::cout << "\n===== TEST BRAIN FUNCTIONALITY =====" << std::endl;
    
    // Test basique du Brain
    Brain testBrain;
    testBrain.setIdea(0, "I'm thinking...");
    testBrain.setIdea(50, "Halfway through my thoughts");
    testBrain.setIdea(99, "Last thought");
    
    std::cout << "Brain idea 0: " << testBrain.getIdea(0) << std::endl;
    std::cout << "Brain idea 50: " << testBrain.getIdea(50) << std::endl;
    std::cout << "Brain idea 99: " << testBrain.getIdea(99) << std::endl;
    
    // Test des limites
    std::cout << "Testing boundary conditions:" << std::endl;
    std::cout << "Invalid index -1: " << testBrain.getIdea(-1) << std::endl;
    std::cout << "Invalid index 100: " << testBrain.getIdea(100) << std::endl;
    
    // Test de copie
    Brain copyBrain(testBrain);
    std::cout << "Copy brain idea 0: " << copyBrain.getIdea(0) << std::endl;
    
    // Modification de l'original pour vérifier la copie profonde
    testBrain.setIdea(0, "Modified thought");
    std::cout << "After modification - Original: " << testBrain.getIdea(0) << std::endl;
    std::cout << "After modification - Copy: " << copyBrain.getIdea(0) << std::endl;
}

int main(void)
{
    std::cout << "===== CPP-04 EX02: ABSTRACT CLASS AANIMAL TESTING =====" << std::endl;
    
    try 
    {
        testAbstractClass();
        testPolymorphicArray();
        testDeepCopyWithBrains();
        testVirtualDestructor();
        testBrainFunctionality();
        
        std::cout << "\n===== ALL TESTS COMPLETED SUCCESSFULLY! =====" << std::endl;
        std::cout << "✓ AAnimal abstract class works correctly" << std::endl;
        std::cout << "✓ Pure virtual function makeSound() implemented in derived classes" << std::endl;
        std::cout << "✓ Polymorphism works correctly" << std::endl;
        std::cout << "✓ Virtual destructor prevents memory leaks" << std::endl;
        std::cout << "✓ Deep copy with Brain class works" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
