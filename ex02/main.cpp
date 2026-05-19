/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:35:19 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 22:35:39 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	// seed random once
	std::srand(std::time(0));

	for (int i = 0; i < 10; i++)
	{
		Base* object = generate();

		std::cout << "pointer:   ";
		identify(object);

		std::cout << "reference: ";
		identify(*object);

		delete object;
	}

	return (0);
}
