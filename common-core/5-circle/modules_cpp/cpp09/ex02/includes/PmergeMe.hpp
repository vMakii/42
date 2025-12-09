/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:17 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 14:42:24 by mivogel          ###   ########.fr       */
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
        
        // ===== FORD-JOHNSON ALGORITHM - VECTOR =====
        // Étape 1: Créer les paires et identifier les gagnants/perdants
        void createPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler);
        
        // Étape 2: Trier récursivement les gagnants
        void sortWinnersVector(std::vector<int>& winners);
        
        // Étape 3: Générer la suite de Jacobsthal pour l'ordre d'insertion
        std::vector<size_t> generateJacobsthalSequence(size_t n);
        
        // Étape 4: Insérer les perdants dans l'ordre optimal
        void insertLosersVector(std::vector<int>& sorted, const std::vector<int>& losers);
        
        // Fonction principale Ford-Johnson pour vector
        void fordJohnsonVector(std::vector<int>& arr);
        
        // ===== FORD-JOHNSON ALGORITHM - DEQUE =====
        void createPairsDeque(std::deque<int>& arr, std::vector<std::pair<int, int> >& pairs, int& straggler);
        void sortWinnersDeque(std::deque<int>& winners);
        void insertLosersDeque(std::deque<int>& sorted, const std::vector<int>& losers);
        void fordJohnsonDeque(std::deque<int>& arr);
        
        // Fonction utilitaire pour l'insertion binaire
        template<typename Container>
        typename Container::iterator binaryInsert(Container& container, 
                                                  typename Container::iterator begin,
                                                  typename Container::iterator end,
                                                  int value);
        
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