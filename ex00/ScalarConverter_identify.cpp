/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_identify.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:51:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>	// std::isprint std::isdigit
#include <cstdlib>	// std::strtol std::strtod
#include <cerrno>	// errno, ERANGE
#include <climits>	// INT_MIN, INT_MAX

// 1. pseudo; special values from the subject
bool	ScalarConverter::isPseudo(const std::string &strValue){
	if (strValue == "nan" || strValue == "+inf" || strValue == "-inf"
		|| strValue == "nanf" || strValue == "+inff" || strValue == "-inff")
		return (true);
	return (false);
}

// 2. char, like 'a', a, or "a", shell converts everything to just a
bool ScalarConverter::isChar(const std::string &strValue)
{
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
bool ScalarConverter::isInt(const std::string &strValue){
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
bool ScalarConverter::isDouble(const std::string &strValue)
{
	char *end;

	// subject says decimal notation, so require a dot
	if (strValue.find('.') == std::string::npos)
		return (false);

	errno = 0;
	std::strtod(strValue.c_str(), &end);

	// valid only if the full string was consumed
	if (*end != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (true);
}

// 5. float, like 4.2f
bool ScalarConverter::isFloat(const std::string &strValue)
{
	std::string strValueWithoutF;

	// float needs to end with 'f'
	if (strValue[strValue.length() - 1] != 'f')
		return (false);
	
	// remove the final 'f'
	strValueWithoutF = strValue.substr(0, strValue.length() - 1);
	
	// reuse same validation as double; float is just a double with sufix 'f'
	return (isDouble(strValueWithoutF));
}
