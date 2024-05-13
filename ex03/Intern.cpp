#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void) { }

Intern&	Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignment operator called" << std::endl;
	return *this;
}

AForm	*Intern::makeForm(std::string const &type, std::string const &target)
{
	const char *formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target),  new ShrubberyCreationForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (type == formNames[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete forms[j];
			}
			return (forms[i]);
		}
	}
	for (int i = 0; i < 3; ++i)
    	delete forms[i];
	throw Intern::FormNotFoundException();
}

char const *Intern::FormNotFoundException::what() const throw() {
	return ("Form Not Founded\n");
}