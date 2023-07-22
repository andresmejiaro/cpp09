/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:25:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 20:58:36 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	PmergeMe numbers(argc, argv);
	
	for (unsigned int i = 0; i < numbers.showV().size(); i++)
		std::cout << numbers.showV()[i] << ",";
	
	return (0);
}