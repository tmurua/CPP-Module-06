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
	// dynamic_cast checks the real object type created behind the Base pointer
	if (dynamic_cast<A*>(p)){
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)){
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)){
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p){
	// with references, throw an exception if it fails
	try{
		A& aReference = dynamic_cast<A&>(p);
		(void)aReference;
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception&){}

	try{
		B& bReference = dynamic_cast<B&>(p);
		(void)bReference;
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception&){}

	try{
		C& cReference = dynamic_cast<C&>(p);
		(void)cReference;
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception&){}
}
