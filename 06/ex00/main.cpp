#include "Convert.hpp"

int	main( int argc, char **argv ) {

	if ( argc != 2 ) {

		std::cerr << "Error" << std::endl;
		return 1;
	}

	Convert	scalar( argv[1] );

	return 0;
}
