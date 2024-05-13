#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		Form(void);
		Form(int sign_grade, int exec_grade);
		Form(const Form &src);
		Form(const std::string &name);
		Form(const std::string &name, int sign_grade, int exec_grade);
		Form &operator=(const Form &src);
		~Form();

		const std::string getName(void) const;
		bool getIsSign(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void beSigned(Bureaucrat &signer);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() override ;
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif