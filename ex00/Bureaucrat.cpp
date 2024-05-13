#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("bureaucrat"), _grade(100) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int _grade) : _name("bureaucrat"), _grade(_grade) {
	std::cout << "Bureaucrat default grade constructor called" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string &_name) : _name(_name), _grade(100) {
	std::cout << "Bureaucrat default name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : _name(_name), _grade(_grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void) { }

const std::string Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::increment(void) {
	std::cout << "increment grade" << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement(void) {
	std::cout << "decrement grade" << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade of Bureaucrat too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade of Bureaucrat too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}