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

	std::cout << "Before : ";
	std::vector<int>::iterator it = abc.begin(), end = abc.end();
	while( it != end){
		std::cout << *it << " ";
		it++;	
	}
	std::cout << std::endl;

	std::clock_t start = std::clock();
    merge_insert(abc);
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000000;
   	
	std::cout << "After vector: ";
	it = abc.begin();
	end = abc.end();
	while( it != end){
		std::cout << *it << " ";
		it++;	
	}
	std::cout << std::endl;
	

	std::list<int> abcd = numbers.showL(), abcdd = numbers.showL();
	
	start = std::clock();
    merge_insert(abcd);
    double duration2 = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 1000000;
	std::cout << "After list: ";
	std::list<int>::iterator itl = abcd.begin(), endl = abcd.end();
	while( itl != endl){
		std::cout << *itl << " ";
		itl++;	
	}
	std::cout << std::endl;
	
	
	std::cout << "Time to process a range of " << abc.size() 
		<<" elements with std:;vector<int>: "<< duration << " us" << std::endl;  
    std::cout << "Time to process a range of " << abcd.size() 
		<<" elements with std:;list<int>: "<< duration2 << " us" << std::endl;  
	return (0);
}

void 	check_move_to_args(unsigned int beginpos,unsigned int size, 
		unsigned int targetpos,unsigned int cont_size){
		if (targetpos > beginpos || beginpos + size > cont_size)
			throw (std::runtime_error("Not compatible"));			
}	

