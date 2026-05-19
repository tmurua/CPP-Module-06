/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:24:30 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 22:33:24 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <iostream>
#include <cstdlib>	// std::rand()

// return one random derived object
Base* generate(void){
	int randomNumber = std::rand() % 3;

	if (randomNumber == 0)
		return (new A());
	if (randomNumber == 1)
		return (new B());
	return (new C());
}

void identify(Base* p){
	// with pointers dynamic_cast returns 0 if it fails
	// so store each result and check which one is not 0
	A* aPointer = dynamic_cast<A*>(p);
	B* bPointer = dynamic_cast<B*>(p);
	C* cPointer = dynamic_cast<C*>(p);

	if (aPointer != 0){
		std::cout << "A" << std::endl;
		return;
	}
	if (bPointer != 0){
		std::cout << "B" << std::endl;
		return;
	}
	if (cPointer != 0){
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p){
	// with references dynamic_cast does not return 0 on failure
	// it throws an exception instead
	try{
		A& aReference = dynamic_cast<A&>(p);
		(void)aReference;
		std::cout << "A" << std::endl;
		return;
	}
	catch (...){}

	try{
		B& bReference = dynamic_cast<B&>(p);
		(void)bReference;
		std::cout << "B" << std::endl;
		return;
	}
	catch (...){
	}

	try{
		C& cReference = dynamic_cast<C&>(p);
		(void)cReference;
		std::cout << "C" << std::endl;
		return;
	}
	catch (...){}
}
