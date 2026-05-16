/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:57:12 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 16:17:09 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include <iostream>
#include <sstream>   // std::ostringstream / std::istringstream (not needed in the simpler version if you don't use them)
#include <iomanip>   // std::fixed, std::setprecision
#include <cstdlib>   // std::atoi, std::strtod, std::strtol
#include <climits>   // INT_MIN, INT_MAX
#include <cfloat>    // FLT_MAX (not needed if you don't use it)
#include <limits>    // std::numeric_limits<type>::min() / max()
#include <cmath>     // math helpers like std::modf, std::isnan, etc. (not needed in the simpler version I gave)
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


