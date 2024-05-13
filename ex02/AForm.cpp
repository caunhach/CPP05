#include "AForm.hpp"

AForm::AForm(void) : _name("form"), _is_signed(false), _sign_grade(30), _exec_grade(60) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &_name, int sign_grade, int exec_grade) : _name(_name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "AForm constructor called" << std::endl;
	if (_sign_grade < 1 || _exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName()), _is_signed(src.getIsSign()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
	std::cout << "AForm Assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_is_signed = src.getIsSign();
	return (*this);
}

AForm::~AForm(void) { }

const std::string AForm::getName(void) const {
	return _name;
}

bool AForm::getIsSign(void) const {
	return _is_signed;
}

int AForm::getSignGrade(void) const {
	return _sign_grade;
}

int AForm::getExecGrade(void) const {
	return _exec_grade;
}

void AForm::beSigned(Bureaucrat &signer) {
	if (signer.getGrade() > getSignGrade())
		throw AForm::FormNotSignedException();
	_is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade of AForm too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade of AForm too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Bureaucrat's Grade is too low to sign Form";
}

const char *AForm::FormIsNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &src) {
	const std::string signValue = src.getIsSign() ? "Yes" : "No";
	os << "AForm name : " << src.getName() << std::endl
		<< "AForm is signed : " << signValue << std::endl
		<< "AForm sign grade : " << src.getSignGrade() << std::endl
		<< "AForm exec grade : " << src.getExecGrade() << std::endl;
	return os;
}