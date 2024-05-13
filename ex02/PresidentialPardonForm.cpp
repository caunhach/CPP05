#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("PPF") { }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm::AForm(src), _target(src._target) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	AForm::operator=(src);
	_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

const std::string PresidentialPardonForm::getTarget(void) const { return (_target); }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw PresidentialPardonForm::PresidentialPardonFormNotExecutableException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

char const *PresidentialPardonForm::PresidentialPardonFormNotExecutableException::what() const throw() {
	return ("Grade of PresidentialPardonForm is too high to execute");
}