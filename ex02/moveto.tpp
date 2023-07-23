/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:26:06 by amejia            #+#    #+#             */
/*   Updated: 2023/07/24 00:17:15 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVETO_HPP
# define MOVETO_HPP

void 	check_move_to_args(unsigned int beginpos,unsigned int size, 
		unsigned int targetpos,unsigned int cont_size);

template <typename T>
void	move_to(std::list<T> &ele, unsigned int beginpos, 
	unsigned int size, unsigned int  targetpos){
	check_move_to_args(beginpos, size, targetpos, ele.size());	
	std::list<T> aux;
	typename std::list<T>::iterator beginit(ele.begin()), endit, targetit;
	
	endit = beginit;
	targetit = beginit;
	std::advance(beginit, beginpos);
	std::advance(endit, size + beginpos);
	std::advance(targetit, targetpos);
	ele.splice(aux.begin(), aux, beginit, endit);
	aux.splice(targetit, ele, aux.begin(), aux.end());
}

template <typename T>
void	move_to(std::vector<T> &ele, unsigned int beginpos, 
	unsigned int size, unsigned int  targetpos){
	std::vector<T> aux;
	
	check_move_to_args(beginpos, size, targetpos, ele.size());	
	for(unsigned int i = 0; i < size; i++){
		aux.push_back(ele[beginpos + i]);
	}
	for (int i =static_cast<int>( beginpos + size  - 1);
		static_cast<int>(i - size) >= static_cast<int>(targetpos); i--)
		ele[i] = ele[i - size];
	for(int i = 0; i < static_cast<int>(size); i++){
		ele[targetpos + i] = aux[i];
	}
}

template <typename T>
void	sorting_group(T &cont, unsigned int pow){
	unsigned int two_pow = 1 << pow;
	int i = 0;
	typename T::iterator it, it2;
	while ( two_pow * i < cont.size() ){
		it = cont.begin();
		it2 = it;
		std::advance(it, two_pow * i + (two_pow >> 1) - 1);
		if (two_pow * (i+1)  > cont.size())
			break ;
		std::advance(it2, two_pow * (i+1) - 1);
		if (*it2 < *it){
			move_to(cont, two_pow * i + (two_pow >> 1), two_pow >> 1, two_pow * i);
		}
	i++;
	}
}

template <typename T>
void	merge_insert(T &cont){
	int i = 1;
	while ( (1 << i) < cont.size()){
		sorting_group(cont, i);
		i++;
	}
	
}

#endif