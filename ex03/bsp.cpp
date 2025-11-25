/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:17:16 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/25 17:44:43 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed vectProduct(Point const &point, Point const &a, Point const &b) {
	return (point.getX() - b.getX()) * (a.getY() - b.getY())
		 - (a.getX() - b.getX()) * (point.getY() - b.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed a1  = vectProduct(point, a, b);
	Fixed a2  = vectProduct(point, b, c);
	Fixed a3  = vectProduct(point, c, a);
	if (a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	if ((a1 < 0 && a2 < 0 && a3 < 0) || (a1 > 0 && a2 > 0 && a3 > 0))
		return (true);
	return (false);
}
