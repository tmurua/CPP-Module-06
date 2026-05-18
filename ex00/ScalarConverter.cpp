/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:51:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>	// std::strtol std::strtod

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}


void	ScalarConverter::convert(const std::string &strValue)
{
	// 1. pseudos are handled separately
	if (isPseudo(strValue)){
		printPseudo(strValue);
		return;
	}
	// 2. char; like 'a'
	else if (isChar(strValue)){
		// first and only char of the string, a numeric value of type char
		char charValue = strValue[0];

		// static_cast converts num type (char) into num type (double), then print
		printAllConversions(static_cast<double>(charValue));
		return;
	}
	// 3. int; like 42
	else if (isInt(strValue)){
		// strtol parses the text into a real integer first
		int intValue = static_cast<int>(std::strtol(strValue.c_str(), NULL, 10));

		// static_cast converts num type (int) into num type (double), then print
		printAllConversions(static_cast<double>(intValue));
		return;
	}
	// 4. double; like 4.2
	else if (isDouble(strValue)){
		// strtod parses string text directly into a double value
		double numValue = std::strtod(strValue.c_str(), NULL);

		printAllConversions(numValue);
		return;
	}
	// 5. float; like 4.2f
	else if (isFloat(strValue)){
		// remove final 'f'
		std::string strValueWithoutF = strValue.substr(0, strValue.length() - 1);

		// strtod parses numeric text as double
		double numValue = std::strtod(strValueWithoutF.c_str(), NULL);

		printAllConversions(numValue);
		return;
	}
	// 6. nothing matched; invalid input
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
