/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 13:51:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <utility>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void mergeInsertVector(std::vector<int>& arr, int left, int right);
        void mergeInsertDeque(std::deque<int>& arr, int left, int right);
        
        // Ford-Johnson alternative implementation
        void fordJohnsonVector(std::vector<int>& arr);
        void fordJohnsonDeque(std::deque<int>& arr);
        size_t getJacobsthal(size_t n);
        void generateJacobsthalSequence(std::vector<size_t>& seq, size_t maxSize);
        template<typename Container>
        void binaryInsert(Container& sorted, int value);
    public:
        // Constructors and Destructor
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        // Member Functions
        void parseInput(int ac, char** av);
        void sortAndDisplay();
};