/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:08:35 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/25 21:21:08 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

#define BITS 8

class Fixed
{
	private:
		int 				rawBits;
		static int const	fractBits = BITS;
	public:
				Fixed();
				Fixed(Fixed const &other);
				~Fixed();
		Fixed	&operator=(Fixed const &other);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};

#endif