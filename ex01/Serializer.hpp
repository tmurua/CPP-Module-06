/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:02:17 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 16:14:57 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <stdint.h>

struct Data{
	// TODO
};

class Serializer{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer	&other(const Serializer &other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);

};

#endif
