/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:25:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/24 00:16:19 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv){
	PmergeMe numbers(argc, argv);
	
	std::list<int> abc = numbers.showL();
		
	merge_insert(abc);
	
	std::list<int>::iterator it;
	it = abc.begin();
	while(it != abc.end()){
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

