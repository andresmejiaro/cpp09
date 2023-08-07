/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:01:54 by amejia            #+#    #+#             */
/*   Updated: 2023/08/07 23:03:14 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Error could not open file.\n";
		return (1);
	}
	try {
		BitcoinExchange Cargar("data.csv");
		Cargar.processInput(argv[1]);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	
	return (0);
}
