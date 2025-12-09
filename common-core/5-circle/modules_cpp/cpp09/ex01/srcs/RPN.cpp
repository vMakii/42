/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:54:58 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/09 12:04:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Private Helper Functions
bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(int a, int b, char op) const
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: Unknown operator");
    }
}

// Constructors and Destructor
RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    this->numbers = other.numbers;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        this->numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN() {}

// Member Functions
void RPN::evaluate(const std::string& expression)
{
    for (size_t i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];
        if (std::isspace(c))
            continue;
        else if (std::isdigit(c))
        {
            this->numbers.push(c - '0');
        }
        else if (isOperator(c))
        {
            if (this->numbers.size() < 2)
                throw std::runtime_error("Error: Insufficient values in expression");
            int b = this->numbers.top(); this->numbers.pop();
            int a = this->numbers.top(); this->numbers.pop();
            int result = applyOperator(a, b, c);
            this->numbers.push(result);
        }
        else
        {
            throw std::runtime_error(std::string("Error: Invalid character '") + c + "'");
        }
    }
    if (this->numbers.size() != 1)
        throw std::runtime_error("Error: The user input has too many values"); 
    std::cout << this->numbers.top() << std::endl;
}