/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:45:41 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/25 23:45:46 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Uso: ./convert <literal>\n";
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
