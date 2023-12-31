/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:27:23 by amejia            #+#    #+#             */
/*   Updated: 2023/08/07 23:23:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

# include <string>
# include <sstream>
# include <iomanip>
# include <cctype>
# include <algorithm>
# include <iostream>

class Date {
public:
	Date();
	Date(const Date&);
	~Date();
	Date (int year, int month, int day);
	Date (std::string string);
	Date&	operator=(const Date&);
	int		getMonth() const;
	int		getDay() const;
	int		getYear() const;
	bool	operator<(const Date&) const;
	bool	checkValid();
	static bool isalphanum(char c);

private:
	bool	__checkLeap();
	bool	__leap;
	int		__year;
	int		__month;
	int		__day;
	bool	__trailing;
};

std::ostream &operator<<(std::ostream &os, const Date &mdate);

#endif // Date_H