/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:15:01 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/16 17:20:34 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
}

/*
=====
TESTS
=====

1) Zero / non-displayable char
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

2) Printable int-to-char conversion
./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0

3) Negative int
./convert -42
char: Non displayable
int: -42
float: -42.0f
double: -42.0

4) Char literal
./convert c
char: 'c'
int: 99
float: 99.0f
double: 99.0

5) Double literal
./convert 4.2
char: Non displayable
int: 4
float: 4.2f
double: 4.2

6) Float literal
./convert 4.2f
char: Non displayable
int: 4
float: 4.2f
double: 4.2

7) Subject example: float 42.0f
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

8) Pseudo-literal: nan
./convert nan
char: impossible
int: impossible
float: nanf
double: nan

9) Pseudo-literal: +inf
./convert +inf
char: impossible
int: impossible
float: +inff
double: +inf

10) Pseudo-literal: -inff
./convert -inff
char: impossible
int: impossible
float: -inff
double: -inf

==========
EDGE CASES
==========

1) Highest printable ASCII character
./convert 126
char: '~'
int: 126
float: 126.0f
double: 126.0

2) First non-displayable value after printable ASCII
./convert 127
char: Non displayable
int: 127
float: 127.0f
double: 127.0

3) Explicit positive int
./convert +42
char: '*'
int: 42
float: 42.0f
double: 42.0

4) INT_MAX
./convert 2147483647
char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0

5) INT_MAX + 1 as int notation
./convert 2147483648
char: impossible
int: impossible
float: impossible
double: impossible

6) INT_MAX + 1 as double notation
./convert 2147483648.0
char: impossible
int: impossible
float: 2147483648.0f
double: 2147483648.0

7) Invalid double: dot at the end
./convert 42.
char: impossible
int: impossible
float: impossible
double: impossible

8) Invalid double: dot at the beginning
./convert .42
char: impossible
int: impossible
float: impossible
double: impossible

9) Invalid float: missing decimal point
./convert 42f
char: impossible
int: impossible
float: impossible
double: impossible

10) Invalid float: double f suffix
./convert 42.0ff
char: impossible
int: impossible
float: impossible
double: impossible

11) Invalid literal
./convert hello
char: impossible
int: impossible
float: impossible
double: impossible
*/
