/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 14:53:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ============= FORD-JOHNSON ALTERNATIVE IMPLEMENTATION =============

// ===== IMPLÉMENTATION POUR VECTOR =====

// Étape 1: Créer les paires et identifier gagnants/perdants
void PmergeMe::createPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler)
{
    straggler = -1;
    pairs.clear();
    
    // Si nombre impair d'éléments, garder le dernier comme straggler
    size_t n = arr.size();
    if (n % 2 != 0)
    {
        straggler = arr[n - 1];
        n--;
    }
    
    // Créer les paires et comparer
    for (size_t i = 0; i < n; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
}

// Étape 2: Trier récursivement les gagnants
void PmergeMe::sortWinnersVector(std::vector<int>& winners)
{
    // Pour de petites tailles, utiliser std::sort
    if (winners.size() <= 1)
        return;
    
    if (winners.size() <= 10)
    {
        std::sort(winners.begin(), winners.end());
        return;
    }
    
    // Sinon, appliquer récursivement Ford-Johnson
    fordJohnsonVector(winners);
}

// Étape 3: Générer la suite de Jacobsthal
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    if (n == 0)
        return jacobsthal;
    
    // Pour 1 élément, retourner simplement [0]
    if (n == 1)
    {
        jacobsthal.push_back(0);
        return jacobsthal;
    }
    
    // Générer les nombres de Jacobsthal: J(n) = J(n-1) + 2*J(n-2)
    // Avec J(0) = 0, J(1) = 1
    std::vector<size_t> jNumbers;
    jNumbers.push_back(0);
    jNumbers.push_back(1);
    
    while (jNumbers.back() < n)
    {
        size_t next = jNumbers[jNumbers.size() - 1] + 2 * jNumbers[jNumbers.size() - 2];
        jNumbers.push_back(next);
    }
    
    // Créer la séquence d'insertion optimale
    size_t lastIndex = 0;
    for (size_t i = 2; i < jNumbers.size() && lastIndex < n; ++i)
    {
        size_t current = jNumbers[i];
        if (current > n)
            current = n;
        
        // Ajouter les indices de current jusqu'à lastIndex+1 (ordre décroissant)
        for (size_t j = current; j > lastIndex && j > 0; --j)
        {
            jacobsthal.push_back(j - 1);
        }
        lastIndex = current;
    }
    
    return jacobsthal;
}

// Fonction template pour l'insertion binaire
template<typename Container>
typename Container::iterator PmergeMe::binaryInsert(Container& /* container */,
                                                     typename Container::iterator begin,
                                                     typename Container::iterator end,
                                                     int value)
{
    return std::lower_bound(begin, end, value);
}

// Étape 4: Insérer les perdants dans l'ordre optimal
void PmergeMe::insertLosersVector(std::vector<int>& sorted, const std::vector<int>& losers)
{
    if (losers.empty())
        return;
    
    // Générer la séquence de Jacobsthal
    std::vector<size_t> insertOrder = generateJacobsthalSequence(losers.size());
    
    // Insérer les perdants dans l'ordre Jacobsthal
    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        size_t idx = insertOrder[i];
        if (idx < losers.size())
        {
            int valueToInsert = losers[idx];
            std::vector<int>::iterator pos = binaryInsert(sorted, sorted.begin(), sorted.end(), valueToInsert);
            sorted.insert(pos, valueToInsert);
        }
    }
}

// Fonction principale Ford-Johnson pour vector
void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
    // Cas de base
    if (arr.size() <= 1)
        return;
    
    // Pour très petites tailles, utiliser std::sort
    if (arr.size() <= 2)
    {
        if (arr.size() == 2 && arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    // Étape 1: Créer les paires (gagnant > perdant)
    std::vector<std::pair<int, int> > pairs;
    int straggler;
    createPairsVector(arr, pairs, straggler);
    
    if (pairs.empty())
        return;
    
    // Étape 2: Extraire les gagnants et trier récursivement avec Ford-Johnson
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    
    // Trier récursivement les gagnants avec Ford-Johnson
    fordJohnsonVector(winners);
    
    // Étape 3: Créer un mapping pour retrouver les perdants associés aux gagnants triés
    // On doit retrouver quel perdant correspond à quel gagnant après le tri
    std::vector<int> sortedLosers;
    for (size_t i = 0; i < winners.size(); ++i)
    {
        // Trouver le gagnant dans les paires originales
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == winners[i])
            {
                sortedLosers.push_back(pairs[j].second);
                // Marquer comme utilisé en mettant une valeur impossible
                pairs[j].first = -1;
                break;
            }
        }
    }
    
    // Étape 4: Construire la chaîne principale (main chain)
    std::vector<int> mainChain;
    
    // Le premier perdant va forcément au début (plus petit que son gagnant)
    if (!sortedLosers.empty())
        mainChain.push_back(sortedLosers[0]);
    
    // Ajouter tous les gagnants triés à la chaîne principale
    for (size_t i = 0; i < winners.size(); ++i)
        mainChain.push_back(winners[i]);
    
    // Étape 5: Insérer les perdants restants selon l'ordre de Jacobsthal
    std::vector<int> pendingElements;
    for (size_t i = 1; i < sortedLosers.size(); ++i)
        pendingElements.push_back(sortedLosers[i]);
    
    insertLosersVector(mainChain, pendingElements);
    
    // Étape 6: Insérer le straggler (élément impair) s'il existe
    if (straggler != -1)
    {
        std::vector<int>::iterator pos = binaryInsert(mainChain, mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    
    // Copier le résultat final
    arr = mainChain;
}

// ===== IMPLÉMENTATION POUR DEQUE =====

void PmergeMe::createPairsDeque(std::deque<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler)
{
    straggler = -1;
    pairs.clear();
    
    size_t n = arr.size();
    if (n % 2 != 0)
    {
        straggler = arr[n - 1];
        n--;
    }
    
    for (size_t i = 0; i < n; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
}

void PmergeMe::sortWinnersDeque(std::deque<int>& winners)
{
    if (winners.size() <= 1)
        return;
    
    if (winners.size() <= 10)
    {
        std::sort(winners.begin(), winners.end());
        return;
    }
    
    fordJohnsonDeque(winners);
}

void PmergeMe::insertLosersDeque(std::deque<int>& sorted, const std::vector<int>& losers)
{
    if (losers.empty())
        return;
    
    std::vector<size_t> insertOrder = generateJacobsthalSequence(losers.size());
    
    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        size_t idx = insertOrder[i];
        if (idx < losers.size())
        {
            int valueToInsert = losers[idx];
            std::deque<int>::iterator pos = binaryInsert(sorted, sorted.begin(), sorted.end(), valueToInsert);
            sorted.insert(pos, valueToInsert);
        }
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    if (arr.size() <= 2)
    {
        if (arr.size() == 2 && arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    std::vector<std::pair<int, int> > pairs;
    int straggler;
    createPairsDeque(arr, pairs, straggler);
    
    if (pairs.empty())
        return;
    
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    
    // Trier récursivement les gagnants avec Ford-Johnson
    fordJohnsonDeque(winners);
    
    // Créer le mapping des perdants triés
    std::vector<int> sortedLosers;
    for (size_t i = 0; i < winners.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == winners[i])
            {
                sortedLosers.push_back(pairs[j].second);
                pairs[j].first = -1;
                break;
            }
        }
    }
    
    std::deque<int> mainChain;
    
    if (!sortedLosers.empty())
        mainChain.push_back(sortedLosers[0]);
    
    for (size_t i = 0; i < winners.size(); ++i)
        mainChain.push_back(winners[i]);
    
    std::vector<int> pendingElements;
    for (size_t i = 1; i < sortedLosers.size(); ++i)
        pendingElements.push_back(sortedLosers[i]);
    
    insertLosersDeque(mainChain, pendingElements);
    
    if (straggler != -1)
    {
        std::deque<int>::iterator pos = binaryInsert(mainChain, mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    
    arr = mainChain;
}

// Constructors and Destructor
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->vec = other.vec;
    this->deq = other.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Member Functions
void PmergeMe::parseInput(int ac, char** av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string str(av[i]);
        
        // Check if string is empty or contains only spaces
        if (str.empty())
            continue;
            
        // Check if all characters are digits
        for (size_t j = 0; j < str.length(); ++j)
        {
            if (!std::isdigit(str[j]))
                throw std::invalid_argument("Error");
        }
        
        int num = atoi(av[i]);
        if (num < 0)
            throw std::invalid_argument("Error");
            
        this->vec.push_back(num);
        this->deq.push_back(num);
    }
}

void PmergeMe::sortAndDisplay()
{
    // Display before
    std::cout << "Before: ";
    size_t displayLimit = this->vec.size() > 5 ? 5 : this->vec.size();
    for (size_t i = 0; i < displayLimit; ++i)
    {
        std::cout << this->vec[i];
        if (i < displayLimit - 1)
            std::cout << " ";
    }
    if (this->vec.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    // Sort vector with timing
    std::vector<int> vecCopy = this->vec;
    clock_t startVec = clock();
    fordJohnsonVector(vecCopy);
    clock_t endVec = clock();
    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    
    // Sort deque with timing
    std::deque<int> deqCopy = this->deq;
    clock_t startDeq = clock();
    fordJohnsonDeque(deqCopy);
    clock_t endDeq = clock();
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    
    // Display after
    std::cout << "After: ";
    for (size_t i = 0; i < displayLimit; ++i)
    {
        std::cout << vecCopy[i];
        if (i < displayLimit - 1)
            std::cout << " ";
    }
    if (vecCopy.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    // Display timing
    std::cout << "Time to process a range of " << this->vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << this->deq.size() 
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}