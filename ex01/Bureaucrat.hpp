#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(int grade);
		Bureaucrat(const std::string &_name);
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat(void);

		const std::string getName(void) const;
		int getGrade(void) const;

		void increment(void);
		void decrement(void);
		void signForm( Form &form );

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() override ;
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif