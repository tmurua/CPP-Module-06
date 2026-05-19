/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:05:25 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 18:14:18 by tmurua           ###   ########.fr       */
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
