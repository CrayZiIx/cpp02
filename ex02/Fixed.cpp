/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:15 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/25 23:46:35 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->rawBits = 0;
	return ;
}

Fixed::Fixed(int const number)
{
	this->rawBits = number << this->fractBits;	
	return ;
}
Fixed::Fixed(float const number)
{
	this->rawBits = roundf(number * (1 << this->fractBits));	
	return ;
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

int		Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return(float(this->rawBits) / float(1 << this->fractBits));	
}

int		Fixed::toInt(void) const
{
	return (this->rawBits >> this->fractBits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &other)
{
	stream << other.toFloat();
	return (stream);
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	this->rawBits = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	return (this->rawBits + other.rawBits);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return (this->rawBits - other.rawBits);
}

Fixed		Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = (long(this->rawBits) * long(fixed.rawBits)) >> Fixed::fractBits;
	return (res);
}

Fixed		Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	res.rawBits = (long(this->rawBits) << long(Fixed::fractBits)) / fixed.rawBits;
	return (res);
}

Fixed		&Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed res(*this);

	this->rawBits++;
	return (res);
}

Fixed		&Fixed::operator--(void)
{
	this->rawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed res(*this);

	this->rawBits--;
	return (res);
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->rawBits <= other.rawBits);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->rawBits == other.rawBits);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->rawBits != other.rawBits);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (b);
	return (a);
}
