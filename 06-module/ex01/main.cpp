/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:46:32 by julberna          #+#    #+#             */
/*   Updated: 2024/06/27 17:26:11 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	printData(Data data);

int main(void) {
	Data	jubs;

	jubs.first_name = "Juliany";
	jubs.last_name = "Bernardo";
	jubs.age = 29;

	println(WHT << "\n   Before serialization:");
	printData(jubs);

	println(WHT << "\n   After serialization:\n");
	println("     pointer: #" << Serializer::serialize(&jubs) << "\n");

	println(WHT << "\n   After deserialization:");
	printData(*Serializer::deserialize(Serializer::serialize(&jubs)));
}

void	printData(Data data) {
	println("");
	println("     First name: " + data.first_name);
	println("     Last name: " + data.last_name);
	println("     Age: " << data.age);
	println("");
}
