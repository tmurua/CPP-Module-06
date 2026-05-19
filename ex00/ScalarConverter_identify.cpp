/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_identify.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:51:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>	// std::isprint std::isdigit
#include <cstddef>	// std::size_t
#include <cstdlib>	// std::strtol std::strtod
#include <cerrno>	// errno, ERANGE
#include <climits>	// INT_MIN, INT_MAX
#include <cfloat>	// FLT_MIN, FLT_MAX

// 1. pseudo; special values from the subject
bool	isPseudo(const std::string &strValue){
	if (strValue == "nan" || strValue == "+inf" || strValue == "-inf"
		|| strValue == "nanf" || strValue == "+inff" || strValue == "-inff")
		return (true);
	return (false);
}

// 2. char, like 'a', a, or "a", shell converts everything to just a
bool	isChar(const std::string &strValue){
	// argv[1] needs to be exacly one character long to be a char
	if (strValue.length() != 1)
		return false;
	// reject non-printable characters.
	if (!std::isprint(strValue[0]))
		return false;
	// Reject digits, "1" should be handled as int, not char
	if (std::isdigit(strValue[0]))
		return false;
	return true;
}

// 3. int, like 42
// long std::strtol(const char* str, char **endptr, int base);
// converts a c-string into a long, stores where parsing stopped at endptr
bool	isInt(const std::string &strValue){
	char *parseEnd;
	long numValue;

	// strtol tries to read a base 10 integer from the string
	errno = 0;
	numValue = std::strtol(strValue.c_str(), &parseEnd, 10);

	// if parseEnd still points to beginning, strtol didn't parse any digits
	if (parseEnd == strValue.c_str())
		return (false);

	// if *parseEnd is not '\0', some extra invalid chars remain, ex. "42abc"
	if (*parseEnd != '\0')
		return (false);

	// even if strtol succeeds, only accept strValues between INT_MIN and INT_MAX
	if (errno == ERANGE)
		return (false);
	if (numValue < INT_MIN || numValue > INT_MAX)
		return (false);

	return (true);
}

// 4. double, like 4.2
// double std::strtod(const char* str, char **endptr);
// converts a c-string into a double, stores where parsing stopped at endptr
bool	isDouble(const std::string &strValue){
	char		*parseEnd;
	std::size_t	dotPos = strValue.find('.');

	// dot is required in double: "42" is an int, not a double
	if (dotPos == std::string::npos)
		return (false);
	// dot can't be the first char, like ".42"
	if (dotPos == 0)
		return (false);
	// char before dot must be a digit: "0.42" or "42.0", not "+.42" or "ab.0"
	if (!std::isdigit(strValue[dotPos - 1]))
		return (false);
	// dot can't be the last char, like "42."
	if (dotPos + 1 >= strValue.length())
		return (false);
	// char after dot must be a digit: "42.0", not "42.f" or "42.+".
	if (!std::isdigit(strValue[dotPos + 1]))
		return (false);
	// set error number to 0 before strtod(), so errors can be stored correctly  
	errno = 0;
	std::strtod(strValue.c_str(), &parseEnd);
	// if parseEnd isn't at the end of strValue, some invalid char was found
	if (*parseEnd != '\0')
		return (false);
	// reject values that are too big or too small for a double
	if (errno == ERANGE)
		return (false);

	return (true);
}

// 5. float, like 4.2f
bool	isFloat(const std::string &strValue){
	std::string strValueWithoutF;
	double		numValue;
	
	// smallest possible syntax for floats: "0.0f", "1.2f", etc.
	if (strValue.length() < 4)
		return (false);
	// float needs to end with 'f'
	if (strValue[strValue.length() - 1] != 'f')
		return (false);
	// remove the final 'f'
	strValueWithoutF = strValue.substr(0, strValue.length() - 1);
	numValue = std::strtod(strValueWithoutF.c_str(), NULL);
	if (numValue < -FLT_MAX || numValue > FLT_MAX)
		return (false);
	// reuse same validation as double; float is just a double with sufix 'f'
	return (isDouble(strValueWithoutF));
}
