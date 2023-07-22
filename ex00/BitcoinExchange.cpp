/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:27:57 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 17:05:17 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&other):
	__historic(std::map<Date,float>(other.getHistoric())){
		
}

BitcoinExchange::BitcoinExchange(std::string file){
	std::ifstream inputFile(file);
	
	if (!inputFile.is_open()){
		throw (std::runtime_error("Error could not open file.\n"));
	}
	
	std::string line;
	while (std::getline(inputFile,line)){
		std::istringstream iss(line);
		std::string s1, s2;
		std::getline(iss, s1, ','); 
		std::getline(iss, s2, ',');
		if (s1 == "date")
			continue ;
		float d1;
		std::istringstream(s2) >> d1;
		__historic[Date(s1)] = d1; 
	}
}


BitcoinExchange::~BitcoinExchange(){
	
}

void BitcoinExchange::printHistoric(){
	for (std::map<Date, float>::iterator it = __historic.begin(); it != __historic.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		this->__historic = other.getHistoric();
	}
	return (*this);
}

const std::map<Date, float> &BitcoinExchange::getHistoric() const{
	return (__historic);
}

void BitcoinExchange::processInput(std::string file){
	std::ifstream inputFile(file);
	
	if (!inputFile.is_open()){
		throw(std::runtime_error("Cannot open file"));
	}
	
	std::string line;
	int skip = 0;
	while (std::getline(inputFile,line)){
		if (skip++ == 0)
			continue ;
		std::istringstream iss(line);
		std::string s1, s2;
		std::getline(iss, s1, '|'); 
		std::getline(iss, s2, '|'); 
		float d1, d2;
		Date current(s1);
		std::istringstream(s2) >> d1;
		if (line.size() == s1.size()){
			std::cout << "Error: bad input => " << line << std::endl;
			continue ; 
		}
		if (!current.checkValid()){
			std::cout << "Error: bad input => " << s1 << std::endl;
			continue ; 
		}
		if (d1 < 0){
			std::cout << "Error: not a positive number." << std::endl;
			continue ; 	
		} 
		if (d1 > 1000){
			std::cout << "Error: too large a number."  << std::endl;
			continue ; 	
		} 
		d2 = (*(--__historic.lower_bound(current))).second;
		std::cout << current << " => " << d1 << " = " << d1 * d2 << std::endl;
	}
}
