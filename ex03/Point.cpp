/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:17:30 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/20 01:01:35 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const value1, float const value2): _x(value1), _y(value2) {
	std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point &copy): _x(copy._x), _y(copy._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Point&	Point::operator=(Point const &) {
	std::cout << "No assignment possible on const values" << std::endl;
	return (*this);
}

Fixed	Point::getX() const {
	return (_x);
}

Fixed	Point::getY() const {
	return (_y);
}
