#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" ){

	std::cout << "Default Ice constructor called" << std::endl;
	return ;
}


Ice::Ice( std::string const &type ) : AMateria( type ) {

	std::cout << "Parameter Ice constructor called" << std::endl;
	return ;
}

Ice::Ice( Ice const &src ) {

	*this = src;
	std::cout << "Copy Ice constructor called" << std::endl;
	return ;
}

Ice::~Ice( void ) {

	std::cout << "Default Ice destructor called" << std::endl;
	return ;
}

Ice	&Ice::operator=( Ice const &rhs ) {

	std::cout << "Assignment Ice operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

AMateria	*Ice::clone( void ) const {

	AMateria	*clone = new Ice();

	return clone;
}

void	Ice::use( ICharacter &target ) {

	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
	return ;
}
