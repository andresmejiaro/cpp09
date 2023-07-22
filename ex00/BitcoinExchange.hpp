/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:11:48 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 15:45:47 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include "Date.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	~BitcoinExchange();
	BitcoinExchange(std::string file);
	BitcoinExchange& operator=(const BitcoinExchange&);
	const std::map<Date, float>	&getHistoric() const; 
	void printHistoric();
	void processInput(std::string file);	
  
private:
	std::map<Date, float>	__historic; 
};

#endif // BitcoinExchange_H