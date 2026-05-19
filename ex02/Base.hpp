/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:18:06 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/19 22:21:26 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base{
public:
	virtual ~Base();
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

// create one random derived object and return it as Base*
Base* generate(void);

// identify real type through a Base pointer
void identify(Base* p);

// identify real type through a Base reference; can't use pointer inside ft
void identify(Base& p);

#endif
