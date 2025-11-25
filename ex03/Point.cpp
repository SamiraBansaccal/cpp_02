/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:17:30 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/25 17:36:43 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(float const value1, float const value2): _x(value1), _y(value2) {}

Point::Point(Point &copy): _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point&	Point::operator=(Point const &) {
	std::cout << "No assignment possible on const values" << std::endl;
	return (*this);
}

Fixed const &	Point::getX() const {
	return (_x);
}

Fixed const &	Point::getY() const {
	return (_y);
}
