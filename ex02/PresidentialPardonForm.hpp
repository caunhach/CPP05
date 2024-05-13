#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm(void);

		const std::string getTarget(void) const;

		void execute(Bureaucrat const &executor) const;
	
	class PresidentialPardonFormNotExecutableException : public std::exception {
		public:
			virtual const char *what() const throw() override;
	};
};

#endif