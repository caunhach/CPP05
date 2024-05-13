#include "Form.hpp"

Form::Form(void) : _name("form"), _is_signed(false), _sign_grade(30), _exec_grade(60) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(int sign_grade, int exec_grade) : _name("form"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "Form default grade constructor called" << std::endl;
}

Form::Form(const std::string &_name) : _name(_name), _is_signed(false), _sign_grade(150), _exec_grade(150) {
	std::cout << "Form default name constructor called" << std::endl;
}

Form::Form(const std::string &_name, int sign_grade, int exec_grade) : _name(_name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "Form constructor called" << std::endl;
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()), _is_signed(src.getIsSign()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src) {
	std::cout << "Form Assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_is_signed = src.getIsSign();
	return (*this);
}

Form::~Form(void) { }

const std::string Form::getName(void) const {
	return _name;
}

bool Form::getIsSign(void) const {
	return _is_signed;
}

int Form::getSignGrade(void) const {
	return _sign_grade;
}

int Form::getExecGrade(void) const {
	return _exec_grade;
}

void Form::beSigned(Bureaucrat &signer) {
	if (signer.getGrade() > getSignGrade())
		throw Form::FormNotSignedException();
	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade of Form too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade of Form too low";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Bureaucrat's Grade is too low to sign Form";
}

std::ostream &operator<<(std::ostream &os, const Form &src) {
	const std::string signValue = src.getIsSign() ? "Yes" : "No";
	os << "Form name : " << src.getName() << std::endl
		<< "Form is signed : " << signValue << std::endl
		<< "Form sign grade : " << src.getSignGrade() << std::endl
		<< "Form exec grade : " << src.getExecGrade() << std::endl;
	return os;
}