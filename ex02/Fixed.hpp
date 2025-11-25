/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:14:37 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/12 23:40:29 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatValue);
		Fixed(Fixed const & copy);
		~Fixed();

		Fixed&	operator=(Fixed const &assignment);
		bool	operator>(Fixed const &comparaison) const;
		bool	operator<(Fixed const &comparaison) const;
		bool	operator>=(Fixed const &comparaison)const;
		bool	operator<=(Fixed const &comparaison)const;
		bool	operator==(Fixed const &comparaison)const;
		bool	operator!=(Fixed const &comparaison)const;
		Fixed	operator+(Fixed const &value)const;
		Fixed	operator-(Fixed const &value)const;
		Fixed	operator*(Fixed const &value)const;
		Fixed	operator/(Fixed const &value)const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	min(Fixed &value1, Fixed &value2);
		static Fixed&	max(Fixed &value1, Fixed &value2);
		static const Fixed&	min(const Fixed	&value1, const Fixed &value2);
		static const Fixed&	max(const Fixed	&value1, const Fixed &value2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream	&out, Fixed const &src);

#endif