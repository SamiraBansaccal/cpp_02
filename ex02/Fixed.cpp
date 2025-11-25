/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:14:11 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/25 17:21:12 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {}

Fixed::Fixed(const int integer) {
	_rawBits = integer << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	_rawBits = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(Fixed const & copy) {
	*this = copy;
}

Fixed::~Fixed() {}

Fixed&	Fixed::operator=(Fixed const & assignment) {
	if (this != &assignment)
		_rawBits = assignment.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalBits);
}

std::ostream&	operator<<(std::ostream	&out, Fixed const &src) {
	out << src.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const &comparaison) const {
	if (_rawBits > comparaison.getRawBits())
		return true;
	return (false);
}

bool	Fixed::operator<(Fixed const &comparaison) const {
	return (_rawBits < comparaison.getRawBits());
}

bool	Fixed::operator>=(Fixed const &comparaison)const {
	return (operator>(comparaison) || operator==(comparaison));
}

bool	Fixed::operator<=(Fixed const &comparaison)const {
	return (operator<(comparaison) || operator==(comparaison));
}

bool	Fixed::operator==(Fixed const &comparaison)const {
	return (_rawBits == comparaison.getRawBits());
}

bool	Fixed::operator!=(Fixed const &comparaison)const {
	return (!operator==(comparaison));
}

Fixed	Fixed::operator+(Fixed const &value)const {
	return Fixed(toFloat() + value.toFloat());
}

Fixed	Fixed::operator-(Fixed const &value)const {
	return Fixed(toFloat() - value.toFloat());
}

Fixed	Fixed::operator*(Fixed const &value)const {
	return Fixed(toFloat() * value.toFloat());
}

Fixed	Fixed::operator/(Fixed const &value)const {
	return Fixed(toFloat() / value.toFloat());
}

Fixed&	Fixed::operator++() {
	++_rawBits;
	return (*this);
}

Fixed&	Fixed::operator--() {
	--_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed old(*this);
	_rawBits++;
	return (old);
}

Fixed	Fixed::operator--(int) {
	Fixed old(*this);
	_rawBits--;
	return (old);
}

Fixed&	Fixed::min(Fixed &value1, Fixed &value2) {
	if (value2 < value1)
		return (value2);
	return (value1);
}

Fixed&	Fixed::max(Fixed &value1, Fixed &value2) {
	if (value2 > value1)
		return (value2);
	return (value1);
}

const Fixed&	Fixed::min(const Fixed	&value1, const Fixed &value2) {
	if (value2 < value1)
		return (value2);
	return (value1);
}

const Fixed&	Fixed::max(const Fixed	&value1, const Fixed &value2) {
	if (value2 > value1)
		return (value2);
	return (value1);
}
