/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 13:51:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ============= FORD-JOHNSON ALTERNATIVE IMPLEMENTATION =============

// Generate Jacobsthal number
size_t PmergeMe::getJacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t result = 0;
    
    for (size_t i = 2; i <= n; ++i)
    {
        result = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = result;
    }
    return result;
}

// Generate Jacobsthal insertion sequence
void PmergeMe::generateJacobsthalSequence(std::vector<size_t>& seq, size_t maxSize)
{
    seq.clear();
    if (maxSize <= 1)
        return;
    
    std::vector<bool> inserted(maxSize, false);
    size_t jacobIdx = 3;
    size_t prevJacob = 1;
    inserted[1] = true; // First element (index 1) already in main chain
    
    while (true)
    {
        size_t currentJacob = getJacobsthal(jacobIdx);
        if (currentJacob >= maxSize)
            currentJacob = maxSize - 1;
        
        // Insert from currentJacob down to prevJacob + 1
        for (size_t i = currentJacob; i > prevJacob && i < maxSize; --i)
        {
            if (!inserted[i])
            {
                seq.push_back(i);
                inserted[i] = true;
            }
        }
        
        if (currentJacob >= maxSize - 1)
            break;
        
        prevJacob = currentJacob;
        jacobIdx++;
    }
    
    // Add any remaining elements not yet inserted
    for (size_t i = 1; i < maxSize; ++i)
    {
        if (!inserted[i])
            seq.push_back(i);
    }
}

// Binary insert for any container
template<typename Container>
void PmergeMe::binaryInsert(Container& sorted, int value)
{
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

// Ford-Johnson for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;
    
    // For very small arrays, use simple insertion sort
    if (n <= 10)
    {
        for (size_t i = 1; i < n; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }
    
    // Step 1: Create pairs with indices to maintain association
    std::vector<std::pair<int, int> > pairs; // (larger, smaller)
    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);
    
    if (hasStraggler)
        straggler = arr[n - 1];
    
    for (size_t i = 0; i < n / 2; ++i)
    {
        int a = arr[i * 2];
        int b = arr[i * 2 + 1];
        pairs.push_back(a > b ? std::make_pair(a, b) : std::make_pair(b, a));
    }
    
    // Step 2: Extract larger elements and sort them recursively
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
    
    fordJohnsonVector(largerElements);
    
    // Step 3: Reorder pairs based on sorted larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == largerElements[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    
    // Step 4: Build main chain
    std::vector<int> result;
    result.push_back(sortedPairs[0].second); // First smaller
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        result.push_back(sortedPairs[i].first); // All larger
    
    // Step 5: Insert remaining smaller elements
    for (size_t i = 1; i < sortedPairs.size(); ++i)
        binaryInsert(result, sortedPairs[i].second);
    
    // Step 6: Insert straggler
    if (hasStraggler)
        binaryInsert(result, straggler);
    
    arr = result;
}

// Ford-Johnson for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;
    
    // For very small arrays, use simple insertion sort
    if (n <= 10)
    {
        for (size_t i = 1; i < n; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }
    
    // Step 1: Create pairs with indices to maintain association
    std::vector<std::pair<int, int> > pairs; // (larger, smaller)
    int straggler = -1;
    bool hasStraggler = (n % 2 != 0);
    
    if (hasStraggler)
        straggler = arr[n - 1];
    
    for (size_t i = 0; i < n / 2; ++i)
    {
        int a = arr[i * 2];
        int b = arr[i * 2 + 1];
        pairs.push_back(a > b ? std::make_pair(a, b) : std::make_pair(b, a));
    }
    
    // Step 2: Extract larger elements and sort them recursively
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
    
    fordJohnsonDeque(largerElements);
    
    // Step 3: Reorder pairs based on sorted larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == largerElements[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    
    // Step 4: Build main chain
    std::deque<int> result;
    result.push_back(sortedPairs[0].second); // First smaller
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        result.push_back(sortedPairs[i].first); // All larger
    
    // Step 5: Insert remaining smaller elements
    for (size_t i = 1; i < sortedPairs.size(); ++i)
        binaryInsert(result, sortedPairs[i].second);
    
    // Step 6: Insert straggler
    if (hasStraggler)
        binaryInsert(result, straggler);
    
    arr = result;
}

// ============= ORIGINAL MERGE-INSERT IMPLEMENTATION =============

// Private Helper Functions
void PmergeMe::mergeInsertVector(std::vector<int>& arr, int left, int right)
{
    if (right - left <= 10)
    {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertVector(arr, left, mid);
    mergeInsertVector(arr, mid + 1, right);
    std::inplace_merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + right + 1);
}

void PmergeMe::mergeInsertDeque(std::deque<int>& arr, int left, int right)
{
    if (right - left <= 10)
    {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertDeque(arr, left, mid);
    mergeInsertDeque(arr, mid + 1, right);
    std::inplace_merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + right + 1);
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
    // mergeInsertVector(vecCopy, 0, vecCopy.size() - 1);  // Old implementation
    fordJohnsonVector(vecCopy);  // Ford-Johnson implementation (FIXED)
    clock_t endVec = clock();
    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    
    // Sort deque with timing
    std::deque<int> deqCopy = this->deq;
    clock_t startDeq = clock();
    // mergeInsertDeque(deqCopy, 0, deqCopy.size() - 1);  // Old implementation
    fordJohnsonDeque(deqCopy);  // Ford-Johnson implementation (FIXED)
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