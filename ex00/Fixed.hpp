/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:28:23 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/10 23:06:10 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const & copy);
		~Fixed();

		Fixed& operator=(Fixed const & assignment);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					_fixed;
		static const int	_fractional = 8;
};

#endif
