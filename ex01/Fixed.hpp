/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:09:15 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/11 22:17:21 by sbansacc         ###   ########.fr       */
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

		Fixed& operator=(Fixed const & assignment);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream	&out, Fixed const &src);

#endif