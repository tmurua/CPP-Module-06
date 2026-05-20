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
#include <cstdlib>	// std::srand()
#include <ctime>	// std::time()

int main(void)
{
	std::srand(std::time(0));	// start random num generator at current time 

	Base* object = generate();

	std::cout << "pointer:   ";
	identify(object);
	std::cout <<  "reference: ";
	identify(*object);

	delete object;
}
