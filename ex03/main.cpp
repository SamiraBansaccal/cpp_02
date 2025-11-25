/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 02:57:36 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/20 00:54:54 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point outside(10, 10);
	Point edge(5, 0);

	std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;  // 1
	std::cout << "outside: " << bsp(a, b, c, outside) << std::endl; // 0
	std::cout << "edge: " << bsp(a, b, c, edge) << std::endl; // 0
}
