/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:17:35 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/25 17:35:05 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(float const value1, float const value2);
		Point(Point &copy);
		~Point();
		Point&	operator=(Point const &);
		Fixed const &	getX() const;
		Fixed const &	getY() const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif