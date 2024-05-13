#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);

		const std::string getTarget(void) const;

		void execute(Bureaucrat const &executor) const;
};

std::string const tree =
"    *\n"
"   ***\n"
"  *****\n"
" *******\n"
"*********\n"
"   |||\n"
;

#endif