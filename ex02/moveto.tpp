/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:26:06 by amejia            #+#    #+#             */
/*   Updated: 2023/07/24 22:41:44 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVETO_HPP
# define MOVETO_HPP
# include <cstdlib>

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
void merge_block(T &cont, unsigned int pos1, unsigned int blocksize){
	unsigned int t1, t2;
	t1 = pos1 + 1;
	t2 = pos1 + blocksize + 1;
	while (t2 < pos1 + 2 * blocksize && t2 < cont.size() && t1 < t2){
		typename T::iterator it1, it2;
		it1 = cont.begin();
		it2 = it1;
		std::advance(it1, t1);
		std::advance(it2, t2);
		if (*it2 < *it1){
			move_to(cont, t2 - 1, 2, t1 -1);
			t2 += 2;
		}
		t1 += 2;
	}
}

template <typename T>
unsigned int	binary_search(T &cont, unsigned int end_pos, int value){
	unsigned int low_pos = 0;
	typename T::iterator it1;
	while (end_pos - low_pos > 1){
		it1 = cont.begin();
		std::advance(it1, (end_pos + low_pos) / 2);
		if (*it1 > value)
			end_pos = (end_pos + low_pos) / 2;
		else
			low_pos = (end_pos + low_pos) / 2;
	}
	return (end_pos);
}


template <typename T>
void	merge_insert(T &cont){
	typename T::iterator it;	
	int i = 1;
	while ( (1 << i) < cont.size() && i < 3){
		sorting_group(cont, i);
		i++;
	}
	for(int j = 2; (1 << j) < cont.size(); j++){
		for (int w = 0; ((w ) * (1 << (j + 1)) + (1 << j)) < (int)cont.size(); w++){
			merge_block(cont, w * (1 << (j + 1)), 1<< j);
		}
	}
	it = cont.begin();
	std::advance(it,2);
	int j = binary_search(cont, 1, *it);
	
	
	
}

#endif