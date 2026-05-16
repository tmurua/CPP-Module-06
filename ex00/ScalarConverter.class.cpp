/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:51:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

#include <iostream>
#include <iomanip>   // std::fixed, std::setprecision
#include <cstdlib>   // std::atoi, std::strtod
#include <climits>   // INT_MIN, INT_MAX
#include <limits>    // std::numeric_limits<char>::min/max
#include <cctype>    // std::isprint


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}


// special values from the subject.
bool	ScalarConverter::isPseudo(const std::string &value){
	if (value == "nan" || value == "+inf" || value == "-inf"
		|| value == "nanf" || value == "+inff" || value == "-inff")
		return (true);
	return (false);
}


// print the 4 output lines for pseudo types, just hardcode 6 possibilities
void ScalarConverter::printPseudo(const std::string &value){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (value == "nanf"){
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (value == "+inff"){
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (value == "-inff"){
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	if (value == "nan"){
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (value == "+inf"){
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (value == "-inf"){
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
}

void	ScalarConverter::convert(const std::string &value)
{
	// 1. pseudo-literals
	if (isPseudo(value)){
		printPseudo(value);
		return;
	}
	// // 2. char; like 'a'
	// else if (isChar(value)){
	// 	// real char is the middle character
	// 	char c = value[1];
	//
	// 	// convert char -> double, then print everything from there
	// 	printFromDouble(static_cast<double>(c));
	// 	return;
	// }
	// // 3. int; like 42
	// else if (isInt(value)){
	// 	int n = static_cast<int>(std::strtol(value.c_str(), 0, 10));
	// 	printFromDouble(static_cast<double>(n));
	// 	return;
	// }
	// // 4. float
	// else if (isFloat(value)){
	// 	// remove final 'f'
	// 	std::string body = value.substr(0, value.length() - 1);
	//
	// 	// parse numeric part as double first
	// 	double number = std::strtod(body.c_str(), 0);
	//
	// 	printFromDouble(number);
	// 	return;
	// }
	// // 5. double
	// else if (isDouble(value)){
	// 	double number = std::strtod(value.c_str(), 0);
	// 	printFromDouble(number);
	// 	return;
	// }
	// 6. nothing matched; invalid input
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
