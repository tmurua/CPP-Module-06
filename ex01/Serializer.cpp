/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:05:25 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 21:03:32 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){
	(void)other;
}

Serializer	&Serializer::operator=(const Serializer &other){
	(void)other;
	return (*this);
}

Serializer::~Serializer(){}

// reinterpret_cast 
// values are not being converted, just a pointer is reinterpreted as an int
uintptr_t	Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

// same idea in reverse; reinterpret the integer back into a pointer to Data 
Data	*Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}


