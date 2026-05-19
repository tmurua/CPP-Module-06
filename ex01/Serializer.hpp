/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:02:17 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 18:08:46 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>	// uintptr_t

struct Data{
	std::string name;
	int			value;
};

class Serializer{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer	&operator=(const Serializer &other);
	~Serializer();

public:
	// convert Data* into an integer type that can hold a pointer
	static uintptr_t	serialize(Data *ptr);
	// convert the integer back into the original pointer type
	static Data			*deserialize(uintptr_t raw);

};

#endif
