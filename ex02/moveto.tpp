/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:20:31 by amejia            #+#    #+#             */
/*   Updated: 2023/07/28 00:15:50 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
std::vector<T>	separate_chain(std::vector<T> & cont){
	typename std::vector<T> secondary;
	typename std::vector<T>::iterator it1, it2, it3;
	it1 = cont.begin();
	while (it1 != cont.end()){
		it2 = it1;
		it2++;
		if (it2 == cont.end()){
			cont.pop_back();
			break ;
		}
		if (*it2 > *it1){
			T temp = *it2;
			*it2 = *it1;
			*it1 = temp;
		}
		secondary.push_back(*it2);
		it3 = it2;
		it3++;
		while (it3 != cont.end()){
			*it2 = *it3;
			it2++;
			it3++;
			if (it3 == cont.end()){
				cont.pop_back();
				break ;
			} 
		}
		it1++;
	}
	return (secondary);
}

template <typename T>
void	merge_step_size(std::vector<T> & cont, std::vector<T> &secondary, 
		int size){
	unsigned int	p1, p2, p3, csiz, lim;
	csiz = cont.size();
	p1 = 0;
	p2 = size;
	lim = p1 + 2 * size;
	while (p2 < csiz)
	{
		while (p1 < p2 && p2 < lim && p2 < csiz){
			T temp, temp2;
			if (cont[p2] < cont[p1]){
				temp = cont[p2];
				temp2 = secondary[p2];
				p3 = p2;
				while (p3 > p1){
					cont[p3] = cont[p3 - 1];
					secondary[p3] = secondary[p3 - 1];
					p3--;
				}
				cont[p1] = temp;
				secondary[p1] = temp2;
				p2 ++;
			}
			p1++;
		}
		p1 = lim;
		p2 = lim + size;
		lim = lim + 2 * size;
	}
}

template <typename T>
void	merge_step_size(std::list<T> & cont, std::list<T> &secondary, 
		int size){
	(void)secondary;
	typename std::list<T>::iterator	p1, p2, p3, lim_it, csiz_it;
	unsigned int csiz, lim;
	csiz = cont.size();
	csiz_it = cont.end();
	p1 = cont.begin();
	p2 = p1;
	std::advance(p2, size);
	lim = 2 * size;
	if (lim < cont.size()){
		lim_it = p1;
		std::advance(lim_it, lim);
	}
	else 
		lim_it = csiz_it;
	while (p2 != csiz_it && lim + 1  < csiz)
	{
		while (p1 != p2 && p2 != lim_it && p2 != csiz_it){
			if (*p2 < *p1){
				p3 = p2;
				p2++;
				cont.splice(p1, cont, p3);
			}
			p1++;
		}
		p1 = lim_it;
		p2 = lim_it;
		if (lim + size < csiz)
			std::advance(p2, size);
		else 
			p2 = csiz_it; 
		lim = lim + 2 * size;
	}
}

template <typename T>
std::list<T>	separate_chain(std::list<T> & cont){
	typename std::list<T> secondary;
	typename std::list<T>::iterator it1, it2, it3, end, send;
	end = cont.end();
	it1 = cont.begin();
	send = secondary.end();
	while (it1 != end){
		it2 = it1;
		it2++;
		if (it2 == end){
			secondary.splice(send, cont, it1);
			break ;
		}
		if (*it2 < *it1)
			secondary.splice(send, cont, it2);
		else {
			secondary.splice(send, cont, it1);
			it1 = it2;
		}
		send = secondary.end();
		it1++;
	}
	return (secondary);
}


template <typename T>
void	merge_insert(T & cont){
	T secondary = separate_chain(cont);
	for (int i = 0; (1 << i) < cont.size(); i++)
		merge_step_size(cont, secondary, 1 << i);
}