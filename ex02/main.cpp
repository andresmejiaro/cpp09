/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:25:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/25 23:56:34 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv){
	PmergeMe numbers(argc, argv);
	
	std::vector<int> abc = numbers.showV();
	std::clock_t start = std::clock();
    merge_insert(abc);
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;  
	

	std::list<int> abcd = numbers.showL();
	start = std::clock();
    merge_insert(abcd);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;  
	
	
	std::list<int>::iterator it;
	it = abcd.begin();
	while(it != abcd.end()){
		std::cout << *it << ",";
		it++;
	}
	std::cout << std::endl;
	
	return (0);
}

void 	check_move_to_args(unsigned int beginpos,unsigned int size, 
		unsigned int targetpos,unsigned int cont_size){
		if (targetpos > beginpos || beginpos + size > cont_size)
			throw (std::runtime_error("Not compatible"));			
}	

