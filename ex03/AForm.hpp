#ifndef AFORM_HPP
# define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		AForm(void);
		AForm(const std::string &name, int sign_grade, int exec_grade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		const std::string getName(void) const;
		bool getIsSign(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void beSigned(Bureaucrat &signer);
		virtual void execute( Bureaucrat const &executor ) const= 0;

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

	class FormIsNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif