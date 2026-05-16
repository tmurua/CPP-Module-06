/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:05:15 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:52:07 by tmurua           ###   ########.fr       */
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

	// helpers to identify which type is the std::string value
	static bool	isPseudo(const std::string &value);
	static bool	isChar(const std::string &value);
	static bool	isInt(const std::string &value);
	static bool	isFloat(const std::string &value);
	static bool	isDouble(const std::string &value);

	// after finding numeric value, print each type
	static void	printPseudo(const std::string &value);
	static void	printFromDouble(double number);
	static void	printChar(double number);
	static void	printInt(double number);
	static void	printFloat(double number);
	static void	printDouble(double number);

public:
	static void	convert(const std::string &value);
};

#endif
