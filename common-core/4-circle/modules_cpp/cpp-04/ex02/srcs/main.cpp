/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/19 21:53:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testBrainBasics()
{
    std::cout << "\n===== TEST BRAIN BASICS =====" << std::endl;
    
    // Test Brain construction and destruction
    Brain* brain1 = new Brain();
    
    // Test setting and getting ideas
    brain1->setIdea(0, "I want to eat fish");
    brain1->setIdea(1, "I love to sleep");
    brain1->setIdea(99, "Last idea");
    
    std::cout << "Brain idea 0: " << brain1->getIdea(0) << std::endl;
    std::cout << "Brain idea 1: " << brain1->getIdea(1) << std::endl;
    std::cout << "Brain idea 99: " << brain1->getIdea(99) << std::endl;
    
    // Test invalid indices
    std::cout << "Brain idea -1: " << brain1->getIdea(-1) << std::endl;
    std::cout << "Brain idea 100: " << brain1->getIdea(100) << std::endl;
    
    delete brain1;
}

void testBrainCopy()
{
    std::cout << "\n===== TEST BRAIN DEEP COPY =====" << std::endl;
    
    Brain original;
    original.setIdea(0, "Original thought");
    original.setIdea(50, "Middle idea");
    
    // Test copy constructor
    Brain copy1(original);
    std::cout << "Copy constructor - idea 0: " << copy1.getIdea(0) << std::endl;
    std::cout << "Copy constructor - idea 50: " << copy1.getIdea(50) << std::endl;
    
    // Test assignment operator
    Brain copy2;
    copy2 = original;
    std::cout << "Assignment operator - idea 0: " << copy2.getIdea(0) << std::endl;
    std::cout << "Assignment operator - idea 50: " << copy2.getIdea(50) << std::endl;
    
    // Modify original to verify deep copy
    original.setIdea(0, "Modified thought");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original idea 0: " << original.getIdea(0) << std::endl;
    std::cout << "Copy1 idea 0: " << copy1.getIdea(0) << std::endl;
    std::cout << "Copy2 idea 0: " << copy2.getIdea(0) << std::endl;
}

void testAnimalBrains()
{
    std::cout << "\n===== TEST ANIMAL BRAINS =====" << std::endl;
    
    // Create animals with brains
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();
    
    // Test polymorphism and proper destruction
    std::cout << "\n--- Testing polymorphic array ---" << std::endl;
    const int arraySize = 6;
    AAnimal* animals[arraySize];
    
    // Fill half with dogs, half with cats
    for (int i = 0; i < arraySize; i++)
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    std::cout << "\n--- Making sounds ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Deleting animals (should call proper destructors) ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Deleting animal " << i << ":" << std::endl;
        delete animals[i];
    }
    
    delete dog1;
    delete cat1;
}

void testDeepCopyAnimals()
{
    std::cout << "\n===== TEST DEEP COPY OF ANIMALS =====" << std::endl;
    
    // Test that Cat and Dog perform deep copy of their brains
    Dog originalDog;
    
    std::cout << "\n--- Testing Dog copy constructor ---" << std::endl;
    Dog copiedDog(originalDog);
    
    std::cout << "\n--- Testing Dog assignment operator ---" << std::endl;
    Dog assignedDog;
    assignedDog = originalDog;
    
    std::cout << "\n--- Testing Cat copy constructor ---" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat);
    
    std::cout << "\n--- Testing Cat assignment operator ---" << std::endl;
    Cat assignedCat;
    assignedCat = originalCat;
    
    std::cout << "\n--- All copies created successfully ---" << std::endl;
}

void testMemoryLeaks()
{
    std::cout << "\n===== TEST MEMORY MANAGEMENT =====" << std::endl;
    
    // Create and immediately delete to test for memory leaks
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n--- Iteration " << i + 1 << " ---" << std::endl;
        AAnimal* animal = (i % 2 == 0) ? static_cast<AAnimal*>(new Dog()) : static_cast<AAnimal*>(new Cat());
        std::cout << "Created " << animal->getType() << std::endl;
        delete animal;
    }
}

int main(void)
{
    std::cout << "===== CPP-04 EX01: BRAIN CLASS TESTING =====" << std::endl;
    
    try 
    {
        testBrainBasics();
        testBrainCopy();
        testAnimalBrains();
        testDeepCopyAnimals();
        testMemoryLeaks();
        
        std::cout << "\n===== ALL TESTS COMPLETED SUCCESSFULLY! =====" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
