/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:18:24 by amejia            #+#    #+#             */
/*   Updated: 2023/07/22 20:55:06 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
# include <vector>
# include <list>
# include <iostream>
# include <sstream>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe&);
	PmergeMe(int argc, char ** argv);
	std::vector<int> showV() const;
	std::list<int> showL() const;
private:
	std::vector<int>	__numbersV;
	std::list<int>		__numbersL;
	int	__checkInput(std::string argvE);
};

#endif // PMergeMe_H