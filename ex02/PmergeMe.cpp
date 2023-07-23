/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:28:45 by amejia            #+#    #+#             */
/*   Updated: 2023/07/24 00:16:53 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other){
	__numbersV = other.showV();
	__numbersL = other.showL();	
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe & other){
	if (this != &other){
		__numbersV = other.showV();
		__numbersL = other.showL();
	}
	return (*this);
}

PmergeMe::PmergeMe(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		int v = __checkInput(argv[i]);
		if (v == -1)
			throw std::runtime_error("Non valid");
		__numbersV.push_back(v);
		__numbersL.push_back(v);
	}
}

std::vector<int>	PmergeMe::showV() const {
	return (__numbersV);
}

std::list<int>	PmergeMe::showL() const {
	return (__numbersL);
}

int	PmergeMe::__checkInput(std::string argvE){
	std::istringstream iss(argvE);
	int j;
	iss >> j;
	
	if (iss.fail() || !iss.eof() || j < 0)
		//throw std::runtime_error("Invalid Input");
		return (-1);
	return (j);
}