/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:50:15 by amejia            #+#    #+#             */
/*   Updated: 2023/07/31 21:07:31 by amejia           ###   ########.fr       */
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
		if (Cargar.showStack().size() < 3 && Cargar.showStack().size() > 1)
			throw (std::runtime_error("Not enough params.\n"));
	}
	//  catch (const std::runtime_error& e) {
	//   // This block will catch exceptions of type std::runtime_error or derived from it
    //     std::cout << "Caught a runtime_error exception: " << e.what() << std::endl;
	// }
	catch (...){
		std::cout << "Error!\n";
	}
	return (0);
}