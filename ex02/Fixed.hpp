/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:08:35 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/25 23:42:49 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

#define BITS 8

class Fixed
{
	private:
		int 				rawBits;
		static int const	fractBits = BITS;
	public:
				Fixed();
				Fixed(int const number);
				Fixed(float const number);
				Fixed(Fixed const &other);
				~Fixed();
		Fixed	&operator=(Fixed const &other);
		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		bool	operator<(Fixed const &other) const;
		bool	operator>(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &other);


#endif