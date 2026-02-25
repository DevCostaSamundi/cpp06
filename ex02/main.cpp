/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:46:29 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 20:53:01 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
	Base* ptr = generate();

	std::cout << "Identificacao via ponteiro: ";
	identify(ptr);

	std::cout << "Identificacao via referencia: ";
	identify(*ptr);

	delete ptr;
	return 0;
}
