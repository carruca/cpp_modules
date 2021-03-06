#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

private:

	std::string const	_name;
	bool				_signed;
	unsigned int const	_signGrade;
	unsigned int const	_executeGrade;
	std::string	const	_target;

public:

	Form( void );
	Form( std::string name, unsigned int signGrade, unsigned int executeGrade, std::string target );
	Form( Form const &src );
	virtual	~Form( void );

	Form	&operator=( Form const &rhs );

	std::string const	&getName( void ) const;
	bool				getSigned( void ) const;
	unsigned int		getSignGrade( void ) const;
	unsigned int		getExecuteGrade( void ) const;
	std::string const	&getTarget( void ) const;

	void				beSigned( Bureaucrat const &signer );

	virtual void		actionExecute( void ) const = 0;
	void				execute( Bureaucrat const &executor ) const;

	class	FormNotSignedException : public std::exception {

	public:
		
		virtual const char	*what() const throw();
	};

	class	GradeTooHighException : public std::exception {

	public:

		virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception {

	public:

		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &o, Form const &rhs );

#endif
