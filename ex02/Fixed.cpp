/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:15 by jolecomt          #+#    #+#             */
/*   Updated: 2024/03/28 13:24:58 by jolecomt         ###   ########.fr       */
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

std::ostream	&operator<<(std::ostream &stream, Fixed const &other)
{
	std::cout<<"Fixed : Left Shift - Bitwise Operator called"<<std::endl;
	stream << other.toFloat();
	return (stream);
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout<<"Fixed : Assignment Operator - Assignment Operator called"<<std::endl;
	this->rawBits = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	std::cout<<"Fixed : Addition - Binary Operator called"<<std::endl;
	return (this->rawBits + other.rawBits);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	std::cout<<"Fixed : Subtraction - Binary Operator called"<<std::endl;
	return (this->rawBits - other.rawBits);
}

Fixed		Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	std::cout<<"Fixed : Multiplication - Binary Operator called"<<std::endl;
	res.rawBits = (long(this->rawBits) * long(fixed.rawBits)) >> Fixed::fractBits;
	return (res);
}

Fixed		Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	std::cout<<"Fixed : Division - Binary Operator called"<<std::endl;
	res.rawBits = (long(this->rawBits) << long(Fixed::fractBits)) / fixed.rawBits;
	return (res);
}

Fixed		&Fixed::operator++(void)
{
	std::cout<<"Fixed : Pre-Increment Operator - Arithmetic Operator called"<<std::endl;
	this->rawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed res(*this);

	std::cout<<"Fixed : Post-Increment Operator - Arithmetic Operator called"<<std::endl;
	this->rawBits++;
	return (res);
}

Fixed		&Fixed::operator--(void)
{
	std::cout<<"Fixed : Pre-Decrement Operator - Arithmetic Operator called"<<std::endl;
	this->rawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed res(*this);

	std::cout<<"Fixed : Post-Decrement Operator - Arithmetic Operator called"<<std::endl;
	this->rawBits--;
	return (res);
}

bool	Fixed::operator<(Fixed const &other) const
{
	std::cout<<"Fixed : Less Than - Relational Operator called"<<std::endl;
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator>(Fixed const &other) const
{
	std::cout<<"Fixed : Greater Than - Relational Operator called"<<std::endl;
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	std::cout<<"Fixed : Less Than or Equal To - Relational Operator called"<<std::endl;
	return (this->rawBits <= other.rawBits);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	std::cout<<"Fixed : Greater Than or Equal To - Relational Operator called"<<std::endl;
	return (this->rawBits >= other.rawBits);
}

bool	Fixed::operator==(Fixed const &other) const
{
	std::cout<<"Fixed : Is Equal To - Relational Operator called"<<std::endl;
	return (this->rawBits == other.rawBits);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	std::cout<<"Fixed : Not Equal To - Relational Operator called"<<std::endl;
	return (this->rawBits != other.rawBits);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	std::cout<<"Fixed : min called"<<std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	std::cout<<"Fixed : max called"<<std::endl;
	if (a < b)
		return (b);
	return (a);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	std::cout<<"Fixed : min(const, const) called"<<std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	std::cout<<"Fixed : max(const, const) called"<<std::endl;
	if (a < b)
		return (b);
	return (a);
}
