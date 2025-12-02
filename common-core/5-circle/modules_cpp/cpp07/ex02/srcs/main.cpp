#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "=== Test de construction et d'initialisation ===" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::cout << "Array de " << numbers.size() << " elements cree" << std::endl;
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Valeurs aleatoires assignees" << std::endl << std::endl;

    std::cout << "=== Test de copie profonde ===" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Copie par affectation et constructeur de copie effectuees" << std::endl;
        std::cout << "Sortie du scope (destruction de tmp et test)..." << std::endl;
    }
    std::cout << "Scope ferme" << std::endl << std::endl;

    std::cout << "=== Verification de l'integrite apres copie ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "OK : Toutes les valeurs sont identiques" << std::endl << std::endl;

    std::cout << "=== Test des exceptions (acces hors limites) ===" << std::endl;
    try
    {
        std::cout << "Tentative d'acces a l'index -2..." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception capturee : " << e.what() << std::endl;
    }
    try
    {
        std::cout << "Tentative d'acces a l'index " << MAX_VAL << "..." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception capturee : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test de modification des elements ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "Toutes les valeurs ont ete modifiees avec succes" << std::endl << std::endl;

    std::cout << "=== Test du constructeur vide ===" << std::endl;
    Array<int> empty;
    std::cout << "Array vide cree, size = " << empty.size() << std::endl << std::endl;

    delete [] mirror;//
    std::cout << "=== Tous les tests sont passes avec succes ===" << std::endl;
    return 0;
}