/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:42:37 by amejia            #+#    #+#             */
/*   Updated: 2023/07
/22 17:42:40 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other){
	__objects = other.showStack();
}

const std::stack<t_RPNtoken> &RPN::showStack() const{
	return (__objects);
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN& other){
	if (this != &other){
		__objects = other.showStack();
	} 
	return (*this);
}

void RPN::read_string(std::string input){
	std::reverse(input.begin(),input.end());
	std::string chara;
	std::istringstream iss(input);
	while (std::getline(iss,chara,' ')){
		__objects.push(create_from_str(chara));
	}
}

t_RPNtoken create_from_str(std::string type){
	t_RPNtoken to_return;
	if (type == "*" || type == "+" || type == "-" || type == "/" ){
		to_return.type = type;
		to_return.value = 0;
	}
	else if (type.size() == 1 && type[0] >= '0' && type[0] <= '9' ){
		to_return.type = "n";
		to_return.value = type[0] - '0';
	}
	else
		throw (std::runtime_error("Wrong parameter\n"));
	return (to_return);	
}

t_RPNtoken create_from_tag(std::string tag, float value){
	t_RPNtoken to_return;
	to_return.type = tag;
	to_return.value = value;
	return (to_return);	
}

void RPN::__oneOperation(){
	float t1,t2;
	t_RPNtoken token;

	if (__objects.size() < 3)
		throw (std::runtime_error("Not enough params to do anything.\n"));
	token = __objects.top();
	if (token.type != "n")
		throw (std::runtime_error("Expecting a number1\n"));	
	t1 = token.value;
	__objects.pop();
	token = __objects.top();
	if (token.type != "n")
		throw (std::runtime_error("Expecting a number2\n"));	
	t2 = token.value;
	__objects.pop();
	token = __objects.top();
	if (token.type == "n")
	{
		__objects.push(create_from_tag("n", t2));
		__oneOperation();
		__objects.push(create_from_tag("n", t1));
		return ;
	}
	if (token.type == "*")
		t1 *= t2;
	if (token.type == "+")
		t1 += t2;
	if (token.type == "-")
		t1 -= t2;
	if (token.type == "/" && t2 != 0)
		t1 /= t2;			
	if (token.type == "/" && t2 == 0)
		throw (std::runtime_error("Division by zero\n"));	
	__objects.pop();
	__objects.push(create_from_tag("n", t1));
}


float RPN::process_RPN(){
	while (__objects.size() > 1)
		__oneOperation();
	if (__objects.top().type != "n")
		throw (std::runtime_error("Result non numeric\n"));	 
	return (__objects.top().value);
}