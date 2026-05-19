/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_print.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:51:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>	// std::numeric_limits<char>::min/max
#include <cctype>	// std::isprint
#include <climits>	// INT_MIN, INT_MAX
#include <iomanip>	// std::fixed, std::setprecision
#include <cmath>	// std::modf
#include <cfloat>	// FLT_MIN, FLT_MAX

// after converting strValue into numValue in convert(), print all outputs
void ScalarConverter::printAllConversions(double numValue){
	printChar(numValue);
	printInt(numValue);
	printFloat(numValue);
	printDouble(numValue);
}

// 1. pseudo
// print the 4 output lines for pseudo types, just hardcode 6 possibilities
void ScalarConverter::printPseudo(const std::string &strValue){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (strValue == "nanf"){
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (strValue == "+inff"){
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (strValue == "-inff"){
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	if (strValue == "nan"){
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (strValue == "+inf"){
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (strValue == "-inf"){
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
}

// 2. char
void ScalarConverter::printChar(double numValue){
	// outside char range -> impossible
	if (numValue < std::numeric_limits<char>::min() ||
		numValue > std::numeric_limits<char>::max()){
		std::cout << "char: impossible" << std::endl;
		return;
	}

	// convert double -> char using static_cast
	char charValue = static_cast<char>(numValue);

	// if char exists but is not printable
	if (!std::isprint(static_cast<unsigned char>(charValue))){
		std::cout << "char: Non displayable" << std::endl;
		return;
	}

	// otherwise print it between quotes
	std::cout << "char: '" << charValue << "'" << std::endl;
}

// 3. int
void ScalarConverter::printInt(double numValue){
	// outside int range -> impossible
	if (numValue < INT_MIN || numValue > INT_MAX){
		std::cout << "int: impossible" << std::endl;
		return;
	}

	// convert double -> int using static_cast
	std::cout << "int: " << static_cast<int>(numValue) << std::endl;
}

// 4. double
void ScalarConverter::printDouble(double numValue){
	double integerPart;
	double fractionalPart;

	// std::modf splits "numValue" into 2 parts, like:
	// 42.0  -> integerPart = 42.0, fractionalPart = 0.0
	// 42.5  -> integerPart = 42.0, fractionalPart = 0.5
	// -3.25 -> integerPart = -3.0, fractionalPart = -0.25
	fractionalPart = std::modf(numValue, &integerPart);

	// if fractionalPart is 0.0, print decimal digit (42.0, not 42)
	// fixed (so cout don't print a big numValue with scientific notation)
	// setprecision to only 1 decimal
	if (fractionalPart == 0.0){
		std::cout << "double: " << std::fixed << std::setprecision(1)
			<< numValue << std::endl;
	}
	else
		// if there is a decimal part, print the numValue normally
		// 42.5 -> "42.5"
		std::cout << "double: " << numValue << std::endl;

	// fixed and setprecision change the formatting state of std::cout
	// this formatting would affect later prints, so reset it
	std::cout.unsetf(std::ios::floatfield);
	std::cout << std::setprecision(6);
}

// 5. float
void ScalarConverter::printFloat(double numValue){
	float floatValue;
	double integerPart;
	double fractionalPart;

	// before converting to float, check if "numValue" fits inside float
	if (numValue < -FLT_MAX || numValue > FLT_MAX){
		std::cout << "float: impossible" << std::endl;
		return;
	}

	// normal explicit conversion from double to float
	floatValue = static_cast<float>(numValue);

	// from here it works the same as printDouble()
	fractionalPart = std::modf(numValue, &integerPart);
	if (fractionalPart == 0.0)
		std::cout << "float: " << std::fixed << std::setprecision(1)
			<< floatValue << "f" << std::endl;
	else
		std::cout << "float: " << floatValue << "f" << std::endl;
	std::cout.unsetf(std::ios::floatfield);
	std::cout << std::setprecision(6);
}

