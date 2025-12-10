/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/10 14:04:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Ford-Johnson Algorithm Implementation

// Step 1: Group elements into n/2 pairs (with potential straggler)
std::vector<std::pair<int, int> > PmergeMe::groupIntoPairs(const std::vector<int>& arr, int& straggler)
{
    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
    
    straggler = -1;
    
    // Create pairs
    for (i = 0; i + 1 < arr.size(); i += 2)
    {
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    
    // Handle straggler if odd number of elements
    if (i < arr.size())
        straggler = arr[i];
    
    return pairs;
}

// Step 2: Compare pairs to identify larger elements
void PmergeMe::comparePairs(std::vector<std::pair<int, int> >& pairs)
{
    // For each pair, ensure first > second (larger element first)
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

// Step 3: Recursively sort the larger elements to create sequence S
std::vector<int> PmergeMe::sortLargerElements(std::vector<std::pair<int, int> >& pairs)
{
    std::vector<int> largerElements;
    
    // Extract larger elements (first element of each pair)
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].first);
    }
    
    // Recursively sort the larger elements
    fordJohnsonVector(largerElements);
    
    // Reorder pairs based on sorted larger elements
    // Create index mapping to preserve pair associations
    std::vector<std::pair<int, int> > sortedPairs;
    sortedPairs.reserve(pairs.size());
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == largerElements[i])
            {
                sortedPairs.push_back(pairs[j]);
                // Mark this pair as used by setting first to -1
                pairs[j].first = -1;
                break;
            }
        }
    }
    pairs = sortedPairs;
    
    return largerElements;
}

// Step 4: Insert the partner of the smallest element at the start
std::vector<int> PmergeMe::insertFirstPartner(const std::vector<std::pair<int, int> >& pairs,
                                               const std::vector<int>& sortedLarger)
{
    std::vector<int> result;
    
    // Insert the smaller element of the first pair at the beginning
    if (!pairs.empty())
        result.push_back(pairs[0].second);
    
    // Add all larger elements (already sorted)
    for (size_t i = 0; i < sortedLarger.size(); ++i)
    {
        result.push_back(sortedLarger[i]);
    }
    
    return result;
}

// Generate Jacobsthal sequence for optimal insertion order
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    
    if (n == 0)
        return jacobsthal;
    
    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    std::vector<size_t> jacobsthalNumbers;
    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);
    
    while (jacobsthalNumbers.back() < n)
    {
        size_t next = jacobsthalNumbers[jacobsthalNumbers.size() - 1] + 
                      2 * jacobsthalNumbers[jacobsthalNumbers.size() - 2];
        jacobsthalNumbers.push_back(next);
    }
    
    // Build insertion sequence based on Jacobsthal numbers
    std::vector<bool> inserted(n + 1, false);
    
    for (size_t i = 2; i < jacobsthalNumbers.size(); ++i)
    {
        size_t current = jacobsthalNumbers[i];
        if (current > n)
            current = n;
        
        size_t prev = jacobsthalNumbers[i - 1];
        
        // Insert in decreasing order from current to prev+1
        for (size_t j = current; j > prev && j > 0; --j)
        {
            if (!inserted[j])
            {
                jacobsthal.push_back(j);
                inserted[j] = true;
            }
        }
    }
    
    // Add any remaining indices not yet inserted
    for (size_t i = 1; i <= n; ++i)
    {
        if (!inserted[i])
            jacobsthal.push_back(i);
    }
    
    return jacobsthal;
}

// Step 5: Insert remaining elements using Jacobsthal sequence with binary search
void PmergeMe::insertRemainingElements(std::vector<int>& result,
                                        const std::vector<std::pair<int, int> >& pairs,
                                        int straggler)
{
    // Generate Jacobsthal sequence for optimal insertion order
    std::vector<size_t> insertionOrder = generateJacobsthalSequence(pairs.size() - 1);
    
    // Insert remaining smaller elements (partners) using Jacobsthal sequence and binary search
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];
        if (idx < pairs.size())
        {
            int toInsert = pairs[idx].second;
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), toInsert);
            result.insert(pos, toInsert);
        }
    }
    
    // Insert straggler if exists
    if (straggler != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    if (arr.size() == 2)
    {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    int straggler;
    
    // Step 1: Group elements into n/2 pairs (with potential straggler)
    std::vector<std::pair<int, int> > pairs = groupIntoPairs(arr, straggler);
    
    // Step 2: Compare pairs to identify larger elements
    comparePairs(pairs);
    
    // Step 3: Recursively sort the larger elements to create sequence S
    std::vector<int> sortedLarger = sortLargerElements(pairs);
    
    // Step 4: Insert the partner of the smallest element at the start
    std::vector<int> result = insertFirstPartner(pairs, sortedLarger);
    
    // Step 5: Insert remaining elements using binary search
    insertRemainingElements(result, pairs, straggler);
    
    arr = result;
}

// ==================== DEQUE IMPLEMENTATION ====================

// Step 1: Group elements into n/2 pairs (with potential straggler)
std::deque<std::pair<int, int> > PmergeMe::groupIntoPairsDeque(const std::deque<int>& arr, int& straggler)
{
    std::deque<std::pair<int, int> > pairs;
    size_t i = 0;
    
    straggler = -1;
    
    // Create pairs
    for (i = 0; i + 1 < arr.size(); i += 2)
    {
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    
    // Handle straggler if odd number of elements
    if (i < arr.size())
        straggler = arr[i];
    
    return pairs;
}

// Step 2: Compare pairs to identify larger elements
void PmergeMe::comparePairsDeque(std::deque<std::pair<int, int> >& pairs)
{
    // For each pair, ensure first > second (larger element first)
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

// Step 3: Recursively sort the larger elements to create sequence S
std::deque<int> PmergeMe::sortLargerElementsDeque(std::deque<std::pair<int, int> >& pairs)
{
    std::deque<int> largerElements;
    
    // Extract larger elements (first element of each pair)
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].first);
    }
    
    // Recursively sort the larger elements
    fordJohnsonDeque(largerElements);
    
    // Reorder pairs based on sorted larger elements
    // Create index mapping to preserve pair associations
    std::deque<std::pair<int, int> > sortedPairs;
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == largerElements[i])
            {
                sortedPairs.push_back(pairs[j]);
                // Mark this pair as used by setting first to -1
                pairs[j].first = -1;
                break;
            }
        }
    }
    pairs = sortedPairs;
    
    return largerElements;
}

// Step 4: Insert the partner of the smallest element at the start
std::deque<int> PmergeMe::insertFirstPartnerDeque(const std::deque<std::pair<int, int> >& pairs,
                                                   const std::deque<int>& sortedLarger)
{
    std::deque<int> result;
    
    // Insert the smaller element of the first pair at the beginning
    if (!pairs.empty())
        result.push_back(pairs[0].second);
    
    // Add all larger elements (already sorted)
    for (size_t i = 0; i < sortedLarger.size(); ++i)
    {
        result.push_back(sortedLarger[i]);
    }
    
    return result;
}

// Generate Jacobsthal sequence for optimal insertion order (deque version)
std::deque<size_t> PmergeMe::generateJacobsthalSequenceDeque(size_t n)
{
    std::deque<size_t> jacobsthal;
    
    if (n == 0)
        return jacobsthal;
    
    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    std::deque<size_t> jacobsthalNumbers;
    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);
    
    while (jacobsthalNumbers.back() < n)
    {
        size_t next = jacobsthalNumbers[jacobsthalNumbers.size() - 1] + 
                      2 * jacobsthalNumbers[jacobsthalNumbers.size() - 2];
        jacobsthalNumbers.push_back(next);
    }
    
    // Build insertion sequence based on Jacobsthal numbers
    std::deque<bool> inserted(n + 1, false);
    
    for (size_t i = 2; i < jacobsthalNumbers.size(); ++i)
    {
        size_t current = jacobsthalNumbers[i];
        if (current > n)
            current = n;
        
        size_t prev = jacobsthalNumbers[i - 1];
        
        // Insert in decreasing order from current to prev+1
        for (size_t j = current; j > prev && j > 0; --j)
        {
            if (!inserted[j])
            {
                jacobsthal.push_back(j);
                inserted[j] = true;
            }
        }
    }
    
    // Add any remaining indices not yet inserted
    for (size_t i = 1; i <= n; ++i)
    {
        if (!inserted[i])
            jacobsthal.push_back(i);
    }
    
    return jacobsthal;
}

// Step 5: Insert remaining elements using Jacobsthal sequence with binary search
void PmergeMe::insertRemainingElementsDeque(std::deque<int>& result,
                                             const std::deque<std::pair<int, int> >& pairs,
                                             int straggler)
{
    // Generate Jacobsthal sequence for optimal insertion order
    std::deque<size_t> insertionOrder = generateJacobsthalSequenceDeque(pairs.size() - 1);
    
    // Insert remaining smaller elements (partners) using Jacobsthal sequence and binary search
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];
        if (idx < pairs.size())
        {
            int toInsert = pairs[idx].second;
            std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), toInsert);
            result.insert(pos, toInsert);
        }
    }
    
    // Insert straggler if exists
    if (straggler != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    if (arr.size() == 2)
    {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }

    int straggler;

    // Step 1: Group elements into n/2 pairs (with potential straggler)
    std::deque<std::pair<int, int> > pairs = groupIntoPairsDeque(arr, straggler);
    
    // Step 2: Compare pairs to identify larger elements
    comparePairsDeque(pairs);
    
    // Step 3: Recursively sort the larger elements to create sequence S
    std::deque<int> sortedLarger = sortLargerElementsDeque(pairs);
    
    // Step 4: Insert the partner of the smallest element at the start
    std::deque<int> result = insertFirstPartnerDeque(pairs, sortedLarger);
    
    // Step 5: Insert remaining elements using Jacobsthal sequence with binary search
    insertRemainingElementsDeque(result, pairs, straggler);
    
    arr = result;
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
    std::set<int> seen;
    
    // Reserve capacity to avoid reallocations
    this->vec.reserve(ac - 1);
    
    for (int i = 1; i < ac; ++i)
    {
        const char* str = av[i];
        
        // Check if string is empty
        if (!str || str[0] == '\0')
            continue;
        
        // Check for sign (negative or positive sign not allowed)
        if (str[0] == '-' || str[0] == '+')
            throw std::invalid_argument("Error");
            
        // Check if all characters are digits
        for (size_t j = 0; str[j] != '\0'; ++j)
        {
            if (!std::isdigit(str[j]))
                throw std::invalid_argument("Error");
        }
        
        // Convert and check for overflow
        char* end;
        long num = std::strtol(str, &end, 10);
        
        // Verify entire string was converted and check range
        if (*end != '\0' || num < 0 || num > 2147483647)
            throw std::invalid_argument("Error");
        
        // Check for duplicates using set (O(log n) instead of O(n))
        if (!seen.insert(static_cast<int>(num)).second)
            throw std::invalid_argument("Error");
            
        this->vec.push_back(static_cast<int>(num));
        this->deq.push_back(static_cast<int>(num));
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