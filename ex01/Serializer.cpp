/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:08:09 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 15:08:10 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Construtor padrão foi chamado" std::endl;
}

Serializer::Serializer(const Serializer& other) {
	std::cout << "Construtor de Cópia foi chamado" << std::endl;
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	std::cout << "Construtor de atribuição foi chamado" << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer() {
	std::cout << "Destrutor foi chamado" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
