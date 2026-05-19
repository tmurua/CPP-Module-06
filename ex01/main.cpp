/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:52:54 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 21:09:31 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

int	main(void)
{
	Data originalData;

	originalData.name = "bender";
	originalData.value = 35;

	Data *originalPtr = &originalData;

	// serialize converts pointer -> uintptr_t
	uintptr_t raw = Serializer::serialize(originalPtr);
	// deserialize converts uintptr_t -> pointer again
	Data *deserializedPtr = Serializer::deserialize(raw);

	std::cout << "original pointer:     " << originalPtr << std::endl;
	std::cout << "serialized int (raw):" << raw << std::endl;
	std::cout << "deserialized pointer: " << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr)
		std::cout << "pointer round-trip: success" << std::endl;
	else
		std::cout << "pointer round-trip: failure" << std::endl;

	// prove deserialized pointer still points to same place 
	std::cout << "name: " << deserializedPtr->name << std::endl;
	std::cout << "value: " << deserializedPtr->value << std::endl;
	if (originalPtr == deserializedPtr)
		std::cout << "same pointer" << std::endl;
}
