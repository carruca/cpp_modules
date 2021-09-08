#include <iostream>
#include "Fixed.hpp"
#include <cmath>

int const	Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _rawBits( 0 ) {

	return ;
}

Fixed::Fixed( int const raw ) : _rawBits( raw << Fixed::_fractBits ) {

	return ;
}

Fixed::Fixed( float const raw ) : _rawBits( (int)(roundf( raw * (1 << Fixed::_fractBits) )) ) {

	return ;
}

Fixed::Fixed( const Fixed &src ) {

	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

	return ;
}

Fixed	&Fixed::operator=( Fixed const &rhs ) {

	this->_rawBits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {

	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {

	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat( void ) const {

	return (float)this->_rawBits / (float)(1 << Fixed::_fractBits);
}

int	Fixed::toInt( void ) const {

	return this->_rawBits >> Fixed::_fractBits;
}

bool	Fixed::operator>( Fixed const &rhs ) const {

	if (this->_rawBits > rhs.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator<( Fixed const &rhs ) const {

	if (this->_rawBits < rhs.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator>=( Fixed const &rhs ) const {

	if (this->_rawBits >= rhs.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator<=( Fixed const &rhs ) const {

	if (this->_rawBits <= rhs.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator==( Fixed const &rhs ) const {

	if (this->_rawBits == rhs.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator!=( Fixed const &rhs ) const {

	if (this->_rawBits != rhs.getRawBits())
		return 1;
	return 0;
}

Fixed	Fixed::operator+( Fixed const &rhs ) const {

	Fixed result( this->toFloat() + rhs.toFloat() );

	return result;
}

Fixed	Fixed::operator-( Fixed const &rhs ) const {

	Fixed	result( this->toFloat() - rhs.toFloat() );

	return result;
}

Fixed	Fixed::operator*( Fixed const &rhs ) const {

	Fixed	result( this->toFloat() * rhs.toFloat() );

	return result;
}

Fixed	Fixed::operator/( Fixed const &rhs ) const {

	Fixed	result( this->toFloat() / rhs.toFloat() );

	return result;
}

Fixed	&Fixed::operator++( void ) {

	this->setRawBits( this->toFloat() + 1 );
	return *this;
}

Fixed	&Fixed::operator--( void ) {

	this->setRawBits( this->toInt() - 1 );
	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed	copy( *this );

	return copy;
}

Fixed	Fixed::operator--( int ) {

	Fixed	copy( *this );

	return copy;
}

std::ostream	&operator<<( std::ostream &o, Fixed const &rhs ) {

	o << rhs.toFloat();
	return o;
}
