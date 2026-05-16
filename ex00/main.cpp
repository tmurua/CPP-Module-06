/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:15:01 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 17:20:34 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
}
