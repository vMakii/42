/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/10 14:02:05 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
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
        
        // Ford-Johnson algorithm for vector
        void fordJohnsonVector(std::vector<int>& arr);
        std::vector<std::pair<int, int> > groupIntoPairs(const std::vector<int>& arr, int& straggler);
        void comparePairs(std::vector<std::pair<int, int> >& pairs);
        std::vector<int> sortLargerElements(std::vector<std::pair<int, int> >& pairs);
        std::vector<int> insertFirstPartner(const std::vector<std::pair<int, int> >& pairs,
                                            const std::vector<int>& sortedLarger);
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        void insertRemainingElements(std::vector<int>& result,
                                      const std::vector<std::pair<int, int> >& pairs,
                                      int straggler);
        
        // Ford-Johnson algorithm for deque
        void fordJohnsonDeque(std::deque<int>& arr);
        std::deque<std::pair<int, int> > groupIntoPairsDeque(const std::deque<int>& arr, int& straggler);
        void comparePairsDeque(std::deque<std::pair<int, int> >& pairs);
        std::deque<int> sortLargerElementsDeque(std::deque<std::pair<int, int> >& pairs);
        std::deque<int> insertFirstPartnerDeque(const std::deque<std::pair<int, int> >& pairs,
                                                 const std::deque<int>& sortedLarger);
        std::deque<size_t> generateJacobsthalSequenceDeque(size_t n);
        void insertRemainingElementsDeque(std::deque<int>& result,
                                           const std::deque<std::pair<int, int> >& pairs,
                                           int straggler);
        
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