#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("SCF") { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	AForm::operator=(src);
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

const std::string ShrubberyCreationForm::getTarget(void) const { return (_target); }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	if (file.is_open()) {
		file << tree;
		file.close();
		std::cout << _target + "_shrubbery" << " has been created" << std::endl;
  	} else {
		std::cout << "Unable to open file";
	}
}
	
