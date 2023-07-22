/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:50:15 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 18:46:04 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Wrong number of parameters.\n";
		return (1);
	}
	RPN Cargar;

	try {
		Cargar.read_string(argv[1]);
		std::cout << Cargar.process_RPN() << std::endl;
		if (Cargar.showStack().size() < 3)
			throw (std::runtime_error("Not enough params.\n"));
	}
	catch (...){
		std::cout << "Error!\n";
	}
	return (0);
}