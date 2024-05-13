#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("RRF") { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm::AForm(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

const std::string RobotomyRequestForm::getTarget(void) const { return (_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw RobotomyRequestForm::RobotomyRequestFormNotExecutableException();
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}

char const *RobotomyRequestForm::RobotomyRequestFormNotExecutableException::what() const throw() {
	return ("Grade of RobotomyRequestForm is too high to execute");
}