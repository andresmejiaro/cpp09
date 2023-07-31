/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:20:31 by amejia            #+#    #+#             */
/*   Updated: 2023/07/31 21:18:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
std::vector<T>	separate_chain(std::vector<T> & cont){
	typename std::vector<T> secondary;
	typename std::vector<T>::iterator it1, it2, it3;
	it1 = cont.begin();
	while (it1 != cont.end())
	{
		it2 = it1;
		it2++;
		if (it2 == cont.end()){
			secondary.push_back(*it1);
			cont.erase(it1);
			break ;
		}
		if (*it2 > *it1){
			secondary.push_back(*it1);
			cont.erase(it1);
			it1 = it2;
		}
		else{
			secondary.push_back(*it2);
			cont.erase(it2);
			it1++;
		}
	}
	return (secondary);
}

template <typename T>
void	merge_step_size(std::vector<T> & cont, std::vector<T> &secondary, 
		int size){
	unsigned int	p1, p2, csiz, lim;
	csiz = cont.size();
	p1 = 0;
	p2 = size;
	lim = p1 + 2 * size;
	while (p2 < csiz)
	{
		while (p1 < p2 && p2 < lim && p2 < csiz){
			if (cont[p2] < cont[p1]){
				std::rotate(cont.begin()+p1,cont.begin() + p2, cont.begin()+p2+1);
				std::rotate(secondary.begin()+p1,secondary.begin() + p2, 
					secondary.begin()+p2+1);
				p2++;
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
	typename std::list<T>::iterator	p1s, p2s, p3s, lim_its;;
	unsigned int csiz, lim;
	csiz = cont.size();
	csiz_it = cont.end();
	p1 = cont.begin();
	p2 = p1;
	p1s = secondary.begin();
	p2s = p1s;
	std::advance(p2, size);
	std::advance(p2s, size);
	lim = 2 * size;
	if (lim < cont.size()){
		lim_it = p1;
		lim_its = p1s;
		std::advance(lim_it, lim);
		std::advance(lim_its, lim);
	}
	else{ 
		lim_it = csiz_it;
		lim_its = p1s;
		std::advance(lim_its, csiz);
	}
	while (lim - size  <= csiz)
	{
		while (p1 != p2 && p2 != lim_it && p2 != csiz_it){
			if (*p2 < *p1){
				p3 = p2;
				p2++;
				cont.splice(p1, cont, p3);
				p3s = p2s;
				p2s++;
				secondary.splice(p1s, secondary, p3s);
			}
			else {
				p1++;
				p1s++;
			}
		}
		p1 = lim_it;
		p2 = lim_it;
		p1s = lim_its;
		p2s = lim_its;
		lim = lim + 2 * size;
		if (lim < csiz){
			std::advance(lim_it, 2 * size);
			std::advance(lim_its, 2 * size);
		}
		else { 
			lim_it = csiz_it;
			lim_its = secondary.begin();
			std::advance(lim_its, csiz);
		}
		if (lim - size < csiz){
			std::advance(p2, size);
			std::advance(p2s, size);
		}
		else { 
			p2 = csiz_it;
			p2s = secondary.begin();
			std::advance(p2s, csiz);
		} 
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
void insert_one(typename std::vector<T> &cont,
	typename std::vector<T> &secondary, 
	typename std::vector<T>::iterator src, 
	typename std::vector<T>::iterator dst){
	cont.insert(dst, *src);
	secondary.erase(src);
}

template <typename T>
void insert_one(typename std::list<T> &cont,
	typename std::list<T> &secondary, 
	typename std::list<T>::iterator src, 
	typename std::list<T>::iterator dst){
	cont.splice(dst, secondary, src);	

}

template <typename T>
unsigned int	binary_search(T &cont, unsigned int end_pos, int value){
	end_pos++;
	unsigned int low_pos = 0;
	typename T::iterator it1;
	while (end_pos - low_pos > 0){
		it1 = cont.begin();
		std::advance(it1, (end_pos + low_pos) / 2);
		if (*it1 > value)
			end_pos = (end_pos + low_pos) / 2;
		else
		{
			if (low_pos == (end_pos + low_pos) / 2)
				return (end_pos);
			low_pos = (end_pos + low_pos) / 2;
		}
	}
	return (end_pos);
}


template <typename T>
void insert_all(T &cont,T &secondary){
	unsigned int	up_end = -1; 
	unsigned int jab_dif[] = {1, 1, 2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526};
	typename T::iterator down_it, down_it2, dst;
	int j = 0;
	while(secondary.size() > 0){
		if (up_end + jab_dif[j] < cont.size())
			up_end += jab_dif[j];
		else
			up_end = cont.size() - 1;
		if (secondary.size() > jab_dif[j]){
			down_it = secondary.begin();
			std::advance(down_it, jab_dif[j] - 1);
		}
		else{
			down_it = secondary.end();
			down_it--;
		}
		int done = 0;
		while(done == 0 && secondary.size() > 0){
			if (down_it == secondary.begin())
				done = 1;
			down_it2 = down_it;
			down_it2--;
			dst = cont.begin();
			int w = binary_search(cont, up_end, *down_it);
			std::advance(dst, w);
			insert_one(cont, secondary, down_it, dst);
			down_it = down_it2;
			up_end++;
		}
		j++;
	}
}

template <typename T>
void	merge_insert(T & cont){
	T secondary = separate_chain(cont);
	for (unsigned int i = 0; static_cast<unsigned int>(1 << i) < cont.size(); i++)
		merge_step_size(cont, secondary, 1 << i);
	typename T::iterator p1, p1s;
	p1 = cont.begin();
	p1s = secondary.begin();
	while (p1 != cont.end()){
		if (*p1s > *p1)
			std::cout << "problem\n";
		p1++;
		p1s++;
	}
	insert_all(cont, secondary);
}