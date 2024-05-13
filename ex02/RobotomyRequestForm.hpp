#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm(void);

		const std::string getTarget(void) const;

		void execute(Bureaucrat const &executor) const;
	
	class RobotomyRequestFormNotExecutableException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
};


#endif