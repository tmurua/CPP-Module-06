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

public:
	static void	convert(const std::string &strValue);
};

#endif
