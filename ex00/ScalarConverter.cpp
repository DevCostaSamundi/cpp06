/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:46:20 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/25 23:46:23 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>



ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string &s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isPseudoLiteral(const std::string &s) {
    return s == "nan" || s == "+nan" || s == "-nan" ||
           s == "nanf" || s == "+nanf" || s == "-nanf" ||
           s == "+inf" || s == "-inf" || s == "inf" ||
           s == "+inff" || s == "-inff" || s == "inff";
}

static bool isFloatLiteral(const std::string &s) {
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    char *end;
    std::strtof(s.c_str(), &end);
    return *end == 'f';
}

static bool isDoubleLiteral(const std::string &s) {
    char *end;
    std::strtod(s.c_str(), &end);
    return *end == '\0' && s.find('.') != std::string::npos;
}

static bool isIntLiteral(const std::string &s) {
    char *end;
    std::strtol(s.c_str(), &end, 10);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;
    bool isPseudo = isPseudoLiteral(literal);

    if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isPseudo) {
        if (literal.find('f') != std::string::npos)
            value = std::strtof(literal.c_str(), NULL);
        else
            value = std::strtod(literal.c_str(), NULL);
    }
    else if (isIntLiteral(literal)) {
        value = static_cast<double>(std::atoi(literal.c_str()));
    }
    else if (isFloatLiteral(literal)) {
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    }
    else if (isDoubleLiteral(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cout << "char: impossível\n";
        std::cout << "int: impossível\n";
        std::cout << "float: impossível\n";
        std::cout << "double: impossível\n";
        return;
    }

    std::cout << "char: ";
    if (isPseudo || value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
        std::cout << "impossível\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Não exibível\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    std::cout << "int: ";
    if (isPseudo || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() ||
        std::isnan(value) || std::isinf(value))
        std::cout << "impossível\n";
    else
        std::cout << static_cast<int>(value) << "\n";


    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf\n";
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff\n" : "+inff\n");
    else {
        float f = static_cast<float>(value);
        if (f == static_cast<int>(f))
            std::cout << f << ".0f\n";
        else
            std::cout << f << "f\n";
    }

    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan\n";
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf\n" : "+inf\n");
    else {
        if (value == static_cast<int>(value))
            std::cout << value << ".0\n";
        else
            std::cout << value << "\n";
    }
}

