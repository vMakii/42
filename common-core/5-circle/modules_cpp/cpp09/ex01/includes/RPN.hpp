/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:45:57 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 11:46:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stack>

class RPN
{
    private:
        std::stack<int> numbers;
        bool isOperator(char c) const;
        int applyOperator(int a, int b, char op) const;
    public:
        // Constructors and Destructor
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        // Member Functions
        void evaluate(const std::string& expression);
};