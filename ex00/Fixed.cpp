/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:15 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/26 00:32:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
	return ;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->rawBits = other.getRawBits();
	return (*this);
}
