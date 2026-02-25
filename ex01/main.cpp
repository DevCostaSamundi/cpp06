/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:05:32 by csamundi          #+#    #+#             */
/*   Updated: 2026/02/11 15:05:46 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main() {
	Data data;
	
	data.id = 42;
	data.name = "Costa";

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	
	std::cout << "Endereco original: " << &data << std::endl;
	std::cout << "Apos desserializar: " << ptr << std::endl;
	
	if (ptr == &data)
		std::cout << "Ponteiros sao iguais. Serializacao OK\n";
	else
		std::cout << "Ponteiros diferentes. Erro.\n";
		
	return 0;
}
