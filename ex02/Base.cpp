/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:31:46 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 20:56:55 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

std::cout << "Construtor padrão foi chamado" std::endl;
std::cout << "Construtor de Cópia foi chamado" << std::endl;
std::cout << "Construtor de atribuição foi chamado" << std::endl;
std::cout << "Destrutor foi chamado" << std::endl;

Base::~Base() {}

Base* generate(void) {
	std::srand(std::time(NULL));
	int r = std::rand() % 3;

	if (r == 0)
		return new A;
	if (r == 1)
		return new B;
	return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	} catch (...) {}
	std::cout << "Unknown\n";
}
