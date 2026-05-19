/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 08:05:15 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/15 16:52:07 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
#define SCALARCONVERTER_CLASS_HPP

#include <string>

class ScalarConverter{
private: //canonical form is private for non instatiable class
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter	&operator=(const ScalarConverter &other);
	~ScalarConverter();

	// helpers to identify which type is the std::string strValue
	static bool	isPseudo(const std::string &strValue);
	static bool	isChar(const std::string &strValue);
	static bool	isInt(const std::string &strValue);
	static bool	isFloat(const std::string &strValue);
	static bool	isDouble(const std::string &strValue);

	// after finding strValue, convert and print each type
	static void	printPseudo(const std::string &strValue);
	static void	printAllConversions(double numValue);
	static void	printChar(double numValue);
	static void	printInt(double numValue);
	static void	printFloat(double numValue);
	static void	printDouble(double numValue);

public:
	static void	convert(const std::string &strValue);
};

#endif
