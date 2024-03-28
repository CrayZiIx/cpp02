/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:15 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/28 13:02:29 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Fixed : Constructor called"<<std::endl;
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(int const number)
{
	std::cout<<"Fixed : Constructor[int const number] called"<<std::endl;
	this->rawBits = number << this->fractBits;	
	return ;
}
Fixed::Fixed(float const number)
{
	std::cout<<"Fixed : Constructor[float const number] called"<<std::endl;
	this->rawBits = roundf(number * (1 << this->fractBits));	
	return ;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout<<"Fixed : Copy constructor called"<<std::endl;
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

float	Fixed::toFloat(void) const
{
	std::cout<<"Fixed : toFloat called"<<std::endl;
	return(float(this->rawBits) / float(1 << this->fractBits));	
}

int		Fixed::toInt(void) const
{
	std::cout<<"Fixed : toInt called"<<std::endl;
	return (this->rawBits >> this->fractBits);
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout<<"Fixed : Assignment Operator called"<<std::endl;
	this->rawBits = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &other)
{
	std::cout<<"Fixed : Left Shift Bitwise Operator called"<<std::endl;
	stream << other.toFloat();
	return (stream);
}

