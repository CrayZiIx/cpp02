/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:15 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/28 12:52:42 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Fixed : Constructor called"<<std::endl;
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout<<"Fixed : Copy Constructor called"<<std::endl;
	*this = other;
	return ;
}

Fixed::~Fixed()
{
	std::cout<<"Fixed : Destructor called"<<std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout<<"Fixed : getRawBits called"<<std::endl;
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout<<"Fixed : setRawBits called"<<std::endl;
	this->rawBits = raw;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout<<"Fixed : Assignment operator called"<<std::endl;
	this->rawBits = other.getRawBits();
	return (*this);
}
