/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:08:49 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/11 22:09:25 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = integer << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & assignment) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assignment)
		_rawBits = assignment.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat( void ) const {
	return (_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalBits);
}

std::ostream&	operator<<(std::ostream	&out, Fixed const &src) {
	out << src.toFloat();
	return (out);
}