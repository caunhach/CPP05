#ifndef INTERN_HPP
# define INTERN_HPP

#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

class AForm;

class Intern {
	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern &operator=(const Intern &src);

		AForm *makeForm(std::string const &type, std::string const &target);

		class FormNotFoundException: public std::exception {
			virtual const char*	what() const throw();
		};
};

#endif