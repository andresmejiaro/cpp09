/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:42:08 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 18:07:37 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
# include <string>
# include <stack>
# include <sstream>
# include <exception>
# include <iostream>

typedef struct s_RPNtoken
{
	std::string type;
	float		value;
} t_RPNtoken;

t_RPNtoken create_from_str(std::string type);
t_RPNtoken create_from_tag(std::string type, float value);

class RPN {
public:
	RPN();
	RPN(const RPN&);
	~RPN();
	RPN& operator=(const RPN&);
	void	read_string(std::string );
	float	process_RPN();
	const std::stack<t_RPNtoken> &showStack() const;


private:
	std::stack<t_RPNtoken> __objects;
	void __oneOperation();
};

#endif // RPN_H