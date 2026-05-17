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
#include <cstdlib>	// std::strtol std::strtod
#include <climits>	// INT_MIN, INT_MAX
#include <cfloat>	// FLT_MIN, FLT_MAX
#include <limits>	// std::numeric_limits<char>::min/max
#include <cctype>	// std::isprint
#include <cerrno>	// errno, ERANGE
#include <iomanip>	// std::fixed, std::setprecision
#include <cmath>	// std::modf

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}


// ----- public convert() -----
void	ScalarConverter::convert(const std::string &value)
{
	// 1. pseudo values
	if (isPseudo(value)){
		printPseudo(value);
		return;
	}
	// 2. char; like 'a'
	else if (isChar(value)){
		// real char is the middle character
		char c = value[1];

		// convert char -> double, then print everything from double
		printFromDouble(static_cast<double>(c));
		return;
	}
	// 3. int; like 42
	else if (isInt(value)){
		int n = static_cast<int>(std::strtol(value.c_str(), 0, 10));

		// convert int -> double, then print
		printFromDouble(static_cast<double>(n));
		return;
	}
	// 4. double; like 4.2
	else if (isDouble(value)){
		double number = std::strtod(value.c_str(), 0);

		printFromDouble(number);
		return;
	}
	// 5. float; like 4.2f
	else if (isFloat(value)){
		// remove final 'f'
		std::string valueWithoutF = value.substr(0, value.length() - 1);

		// parse numeric part as double first
		double number = std::strtod(valueWithoutF.c_str(), 0);

		printFromDouble(number);
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

// ----- find type helpers: -----
// 1. pseudo; special values from the subject
bool	ScalarConverter::isPseudo(const std::string &value){
	if (value == "nan" || value == "+inf" || value == "-inf"
		|| value == "nanf" || value == "+inff" || value == "-inff")
		return (true);
	return (false);
}

// 2. char, like 'a' - it has 3 characteres: index 0 = '; 1 = char itself; 2 = '
bool ScalarConverter::isChar(const std::string &value){
	if (value.length() != 3)
		return (false);
	if (value[0] != '\'')
		return (false);
	if (value[2] != '\'')
		return (false);
	return (true);
}

// 3. int, like 42
// long std::strtol(const char* str, char **endptr, int base);
// converts a c-string into a long, stores where parsing stopped at endptr
bool ScalarConverter::isInt(const std::string &value){
	char *end;
	long number;

	if (value.empty())
		return (false);

	// strtol tries to read a base 10 integer from the string
	errno = 0;
	number = std::strtol(value.c_str(), &end, 10);

	// if *end is not '\0', it means some extra invalid characters remain.
	// "42abc" would fail for ex.
	if (*end != '\0')
		return (false);

	// even if strtol succeeds, only accept values between INT_MIN and INT_MAX
	if (errno == ERANGE)
		return (false);
	if (number < INT_MIN || number > INT_MAX)
		return (false);

	return (true);
}

// 4. double, like 4.2
// double std::strtod(const char* str, char **endptr);
// converts a c-string into a double, stores where parsing stopped at endptr
bool ScalarConverter::isDouble(const std::string &value)
{
	char *end;

	// subject says decimal notation, so require a dot
	if (value.find('.') == std::string::npos)
		return (false);

	errno = 0;
	std::strtod(value.c_str(), &end);

	// valid only if the full string was consumed
	if (*end != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (true);
}

// 5. float, like 4.2f
bool ScalarConverter::isFloat(const std::string &value)
{
	std::string valueWithoutF;

	// smallest float would be something like "0f" or "0.0f", but subject says
	// decimal notation, so we need a dot too
	if (value.length() < 2)
		return (false);

	// float needs to end with 'f'
	if (value[value.length() - 1] != 'f')
		return (false);
	
	// remove the final 'f'
	valueWithoutF = value.substr(0, value.length() - 1);
	
	// reuse same validation as double; float is just a double with a 'f'
	return (isDouble(valueWithoutF));
}

// ----- print helpers: -----
// 1. pseudo
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

// 2. char
void ScalarConverter::printChar(double number){
	// if number is outside char range, conversion is impossible
	if (number < std::numeric_limits<char>::min() ||
		number > std::numeric_limits<char>::max()){
		std::cout << "char: impossible" << std::endl;
		return;
	}

	// convert explicitly using static_cast
	char c = static_cast<char>(number);

	// if char exists but is not printable, say so
	if (!std::isprint(static_cast<unsigned char>(c))){
		std::cout << "char: Non displayable" << std::endl;
		return;
	}

	// otherwise print it with quotes
	std::cout << "char: '" << c << "'" << std::endl;
}

// 3. int
void ScalarConverter::printInt(double number)
{
	// outside int range -> impossible
	if (number < INT_MIN || number > INT_MAX){
		std::cout << "int: impossible" << std::endl;
		return;
	}

	// normal explicit scalar conversion
	std::cout << "int: " << static_cast<int>(number) << std::endl;
}

// 4. double
void ScalarConverter::printDouble(double number)
{
	double integerPart;
	double fractionalPart;

	// std::modf splits "number" into 2 parts, like:
	// 42.0  -> integerPart = 42.0, fractionalPart = 0.0
	// 42.5  -> integerPart = 42.0, fractionalPart = 0.5
	// -3.25 -> integerPart = -3.0, fractionalPart = -0.25
	fractionalPart = std::modf(number, &integerPart);

	// if fractionalPart is 0.0, print decimal digit (42.0, not 42)
	// fixed (so cout don't print a big number with scientific notation)
	// setprecision to only 1 decimal
	if (fractionalPart == 0.0){
		std::cout << "double: " << std::fixed << std::setprecision(1)
			<< number << std::endl;
	}
	else{
		// if there is a decimal part, print the number normally
		// 42.5 -> "42.5"
		std::cout << "double: " << number << std::endl;
	}

	// fixed and setprecision change the formatting state of std::cout
	// that formatting would affect later prints too, so we reset it
	std::cout.unsetf(std::ios::floatfield);
	std::cout << std::setprecision(6);
}

// 5. float
void ScalarConverter::printFloat(double number)
{
	float f;
	double integerPart;
	double fractionalPart;

	// before converting to float, check if "number" fits inside float
	if (number < -FLT_MAX || number > FLT_MAX){
		std::cout << "float: impossible" << std::endl;
		return;
	}

	// normal explicit conversion from double to float
	f = static_cast<float>(number);

	// std::modf splits the ORIGINAL double "number" into:
	// - integerPart    -> the part before the decimal point
	// - fractionalPart -> the part after the decimal point
	//
	// We use this only to decide the output format.
	// Examples:
	// 42.0 -> fractionalPart = 0.0  -> print "42.0f"
	// 42.5 -> fractionalPart = 0.5  -> print "42.5f"
	fractionalPart = std::modf(number, &integerPart);

	// Whole number:
	// print one decimal digit so the output matches the subject style.
	if (fractionalPart == 0.0){
		std::cout << "float: " << std::fixed << std::setprecision(1) << f
			<< "f" << std::endl;
	}
	else{
		// Non-whole number:
		// print normally, then add the required 'f' suffix for float.
		std::cout << "float: " << f << "f" << std::endl;
	}

	// Reset formatting so later prints are not forced to use fixed / 1 decimal digit.
	std::cout.unsetf(std::ios::floatfield);
	std::cout << std::setprecision(6);
}

// central helper:
// once we have one numeric value, print all 4 target outputs from it.
void ScalarConverter::printFromDouble(double number){
	printChar(number);
	printInt(number);
	printFloat(number);
	printDouble(number);
}

