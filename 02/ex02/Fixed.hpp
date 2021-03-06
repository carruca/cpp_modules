#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

public:

	Fixed( void );
	Fixed( int const raw );
	Fixed( float const raw );
	Fixed( Fixed const &src );
	~Fixed( void );

	Fixed	&operator=( Fixed const &rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator>( Fixed const &rhs ) const;
	bool	operator<( Fixed const &rhs ) const;
	bool	operator>=( Fixed const &rhs ) const;
	bool	operator<=( Fixed const &rhs ) const;
	bool	operator==( Fixed const &rhs ) const;
	bool	operator!=( Fixed const &rhs ) const;

	Fixed	operator+( Fixed const &rhs ) const;
	Fixed	operator-( Fixed const &rhs ) const;
	Fixed	operator*( Fixed const &rhs ) const;
	Fixed	operator/( Fixed const &rhs ) const;

	Fixed	&operator++( void );
	Fixed	&operator--( void );
	Fixed	operator++( int );
	Fixed	operator--( int );

	static Fixed		&min( Fixed &lhs, Fixed &rhs );
	static Fixed const	&min( Fixed const &lhs, Fixed const &rhs );
	static Fixed const	&max( Fixed const &lhs, Fixed const &rhs );
	static Fixed		&max( Fixed &lhs, Fixed &rhs );

private:

	int		_rawBits;

	static int const	_fractBits;

};

std::ostream	&operator<<( std::ostream &o, Fixed const &rhs );

#endif
