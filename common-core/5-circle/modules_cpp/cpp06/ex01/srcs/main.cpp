/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/12/01 10:47:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data originalData;
    originalData.value = 42;
    originalData.name = "Test Data";

    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << std::endl;

    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "=== Serialized ===" << std::endl;
    std::cout << "Raw value: " << serialized << std::endl;
    std::cout << std::endl;

    // Deserialize back to pointer
    Data* deserializedData = Serializer::deserialize(serialized);
    std::cout << "=== Deserialized Data ===" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "Value: " << deserializedData->value << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << std::endl;

    // Verify pointers are equal
    if (&originalData == deserializedData)
        std::cout << "✓ Success: Original and deserialized pointers are identical!" << std::endl;
    else
        std::cout << "✗ Error: Pointers differ!" << std::endl;

    return 0;
}
