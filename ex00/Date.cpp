/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:28:50 by amejia            #+#    #+#             */
/*   Updated: 2023/08/02 23:56:45 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(): __year(0), __month(0), __day(0), __trailing(0){
	__leap = this->__checkLeap();
}

Date::Date(const Date&other): __year(other.getYear()),__month(other.getMonth()),
	__day(other.getDay()){
	__leap = this->__checkLeap();
	__trailing = 0;
}

Date::Date(int year, int month, int day): __year(year),__month(month),
	__day(day){
	__leap = this->__checkLeap();
	__trailing = 0;		
}

Date::~Date(){
	
}

Date::Date(std::string str){
	std::string year, month, day, leftover, left;
	__year = -1;
	__month = -1;
	__day = -1;
	__trailing = 0;
	std::istringstream iss(str);
	std::getline(iss, year, '-');
	std::getline(iss, month, '-');
	std::getline(iss, day, '-');
	std::istringstream is1(year);
	is1 >> __year;
	std::istringstream is2(month);
	is2 >> __month;
	std::istringstream is3(day); 
	is3 >> __day;	
	std::getline(is1,leftover);
	if (leftover.size() >0 && std::find_if(leftover.begin(), leftover.end(),
		isalphanum) != leftover.end())
		__trailing = 1;
	std::getline(is2,leftover);
	if (leftover.size() >0 && std::find_if(leftover.begin(), leftover.end(),
		isalphanum) != leftover.end())
		__trailing = 1;
	std::getline(is3,leftover);
	if (leftover.size() >0 && std::find_if(leftover.begin(), leftover.end(),
		isalphanum) != leftover.end())
		__trailing = 1;
	std::getline(iss,leftover);
	if (leftover.size() >0 && std::find_if(leftover.begin(), leftover.end(),
		isalphanum) != leftover.end())
		__trailing = 1;
}


int	Date::getMonth() const {
	return (__month);
}

int	Date::getDay() const {
	return (__day);
}

int	Date::getYear() const {
	return (__year);
}

bool	Date::checkValid(){
	if (__trailing != 0)
		return (0);
	if (__day < 1)
		return (0);
	if (__year < 1000 || __year > 9999)
		return (0);
	if (__month < 1 || __month > 12)
		return (0);
	if ((__month == 4 || __month == 6 || __month == 9 || __month == 11)
			&& __day > 30)
		return (0); 
	if ((__month == 1 || __month == 3 || __month == 5 || __month == 7 
			|| __month == 8 || __month == 10 || __month == 12)
			&& __day > 31)
		return (0); 
	if (__month == 2 && __leap && __day > 29)
		return (0); 	
	if (__month == 2 && !__leap && __day > 28)
		return (0); 	
	return (1);
}

bool	Date::operator<(const Date &other) const{
	if (this->getYear() < other.getYear())
		return (1);
	else if ((this->getMonth() < other.getMonth()) 
		&& (this->getYear() == other.getYear()))
		return (1);
	else if ((this->getDay() < other.getDay())
		&& (this->getMonth() == other.getMonth()) 
		&& (this->getYear() == other.getYear()))
		return (1);
	return (0);
}

bool Date::__checkLeap(){
	if (__year % 4 == 0){
		if (__year % 400 == 0)
			return (true);
		else if (__year % 100 == 0)
			return (false);
		return (true);
	}
	return (false);
}

bool Date::isalphanum(char c){
	return (std::isalnum(static_cast<unsigned char>(c)));
}

std::ostream &operator<<(std::ostream &os, const Date &mdate){
os <<  mdate.getYear() << "-" <<std::setw(2) << std::setfill('0') <<
	std::setw(2) << std::setfill('0') << mdate.getMonth() << "-"  << 
	std::setw(2) << std::setfill('0') << mdate.getDay();
return (os);	
}