#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <cassert>
#include <sstream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

void testBureaucratDefaultConstructor() {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    Bureaucrat* a = new Bureaucrat();

    std::cout.rdbuf(oldCout);

    std::string expectedOutput = "Bureaucrat default constructor called\n";
    std::string actualOutput = buffer.str();

    assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Default Constructor Call's Message correct\n" << RESET;
    assert(a->getName() == "bureaucrat");
	std::cout << GREEN << "   " << "\u2714" << " Constructor Call's Name correct\n" << RESET;
    assert(a->getGrade() == 100);
	std::cout << GREEN << "   " << "\u2714" << " Constructor Call's Grade correct\n" << RESET;

    delete a;
}

void testBureaucratGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat* b = new Bureaucrat(1);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Bureaucrat default grade constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Grade Constructor Call's Message correct\n" << RESET;
	assert(b->getName() == "bureaucrat");
	std::cout << GREEN << "   " << "\u2714" << " Grade Constructor Call's Name correct\n" << RESET;
	assert(b->getGrade() == 1);
	std::cout << GREEN << "   " << "\u2714" << " Grade Constructor Call's Grade correct\n" << RESET;

	delete b;
}

void testBureaucratNameConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat* c = new Bureaucrat("person");

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Bureaucrat default name constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Name Constructor Call's Message correct\n" << RESET;
	assert(c->getName() == "person");
	std::cout << GREEN << "   " << "\u2714" << " Name Constructor Call's Name correct\n" << RESET;
	assert(c->getGrade() == 100);
	std::cout << GREEN << "   " << "\u2714" << " Name Constructor Call's Grade correct\n" << RESET;

	delete c;
}

void testBureaucratNameGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat* d = new Bureaucrat("person", 1);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Bureaucrat constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Constructor Call's Message correct\n" << RESET;
	assert(d->getName() == "person");
	std::cout << GREEN << "   " << "\u2714" << " Constructor Call's Name correct\n" << RESET;
	assert(d->getGrade() == 1);
	std::cout << GREEN << "   " << "\u2714" << " Constructor Call's Grade correct\n" << RESET;

	delete d;
}

void testBureaucratCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat* a = new Bureaucrat();
	Bureaucrat* e = new Bureaucrat(*a);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Bureaucrat default constructor called\nBureaucrat Copy constructor called\nBureaucrat Assignment operator called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Copy Constructor Call's Message correct\n" << RESET;
	assert(e->getName() == "bureaucrat");
	std::cout << GREEN << "   " << "\u2714" << " Copy Constructor Call's Name correct\n" << RESET;
	assert(e->getGrade() == 100);
	std::cout << GREEN << "   " << "\u2714" << " Copy Constructor Call's Grade correct\n" << RESET;

	delete a;
	delete e;
}

void testBureaucratAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat* b = new Bureaucrat(1);
	Bureaucrat* f = new Bureaucrat();
	*f = *b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Bureaucrat default grade constructor called\nBureaucrat default constructor called\nBureaucrat Assignment operator called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Assignment Operator Call's Message correct\n" << RESET;
	assert(f->getName() == "bureaucrat");
	std::cout << GREEN << "   " << "\u2714" << " Assignment Operator Call's Name correct\n" << RESET;
	assert(f->getGrade() == 1);
	std::cout << GREEN << "   " << "\u2714" << " Assignment Operator Call's Grade correct\n" << RESET;

	delete b;
	delete f;
}

void testGradeBelowOne() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 0);

		std::cout.rdbuf(oldCout);
		assert(false && "Expected exception was not thrown");
	} catch (std::exception &e) {
		std::string expectedOutput = "Grade of Bureaucrat too high";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " GradeTooHighException's message correct\n" << RESET;
	}
}

void testGradeOnetoOneHundredFifty() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 4);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " Test passed with no exception\n" << RESET;
	} catch (std::exception &e) {
		assert(false && "this condition should not thrown");
	}
}

void testGradeOverOneHundredFifty() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 151);
		std::cout.rdbuf(oldCout);
		assert(false && "Expected exception was not thrown");
	} catch (std::exception &e) {
		std::string expectedOutput = "Grade of Bureaucrat too low";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " GradeTooLowException's message correct\n" << RESET;
	}
}

void testIncrementWithGradeOne() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 1);
		b.increment();
		std::cout.rdbuf(oldCout);
		assert(false && "Expected exception was not thrown");
	} catch (std::exception &e) {
		std::string expectedOutput = "Grade of Bureaucrat too high";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " [Case 1: Grade = 1] GradeTooHighException\n" << RESET;
	}
}

void testIncrementWithGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 77);
		b.increment();
		std::cout.rdbuf(oldCout);
		assert(b.getGrade() == 76);
		std::cout << GREEN << "   " << "\u2714" << " [Case 2: Grade = 77] Test passed with corrected grade after increment\n" << RESET;
	} catch (std::exception &e) {
		assert(false && "this condition should not thrown");	
	}
}

void testDecrementWithGradeOneHundredFifty() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 150);
		b.decrement();
		std::cout.rdbuf(oldCout);
		assert(false && "Expected exception was not thrown");
	} catch (std::exception &e) {
		std::string expectedOutput = "Grade of Bureaucrat too low";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " [Case 1: Grade = 150] GradeTooLowException\n" << RESET;
	}
}

void testDecrementWithGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Bureaucrat b("person", 50);
		b.decrement();
		std::cout.rdbuf(oldCout);
		assert(b.getGrade() == 51);
		std::cout << GREEN << "   " << "\u2714" << " [Case 2: Grade = 50] Test passed with corrected grade after decrement\n" << RESET;
	} catch (std::exception &e) {
		assert(false && "this condition should not thrown");
	}
}

void testInsertionOperatorforDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
	
	Bureaucrat b;

	std::cout << b << std::endl;
	
	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat default constructor called\nbureaucrat, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Default Constructor\n" << RESET;
}

void testInsertionOperatorforGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat b(100);

	std::cout << b << std::endl;

	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat default grade constructor called\nbureaucrat, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Grade Constructor\n" << RESET;
}

void testInsertionOperatorforNameConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat b("person");

	std::cout << b << std::endl;

	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat default name constructor called\nperson, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Name Constructor\n" << RESET;
}

void testInsertionOperatorforNameGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat b("person", 100);

	std::cout << b << std::endl;

	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat constructor called\nperson, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Name and Grade Constructor\n" << RESET;
}

void testInsertionOperatorforCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat a("person", 100);
	Bureaucrat b(a);

	std::cout << b << std::endl;

	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat constructor called\nBureaucrat Copy constructor called\nBureaucrat Assignment operator called\nperson, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testInsertionOperatorforAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Bureaucrat a("person", 100);
	Bureaucrat b = a;

	std::cout << b << std::endl;

	std::cout.rdbuf(oldCout);

	assert(buffer.str() == "Bureaucrat constructor called\nBureaucrat Copy constructor called\nBureaucrat Assignment operator called\nperson, bureaucrat grade 100\n");
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Assignment Operator\n" << RESET;
}

void testPresidentialPardonFormDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm *a = new PresidentialPardonForm();

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Default Constructor Call's Message correct\n" << RESET;
	assert(a->getName() == "PresidentialPardonForm");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Constructor Call's Name correct\n" << RESET;
	assert(a->getTarget() == "PPF");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Constructor Call's Target correct\n" << RESET;
	assert(a->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Constructor Call's IsSign correct\n" << RESET;
	assert(a->getSignGrade() == 25);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Constructor Call's SignGrade correct\n" << RESET;
	assert(a->getExecGrade() == 5);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Constructor Call's ExecuteGrade correct\n" << RESET;

	delete a;
}

void testRobotomyRequestFormDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm *a = new RobotomyRequestForm();

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Default Constructor Call's Message correct\n" << RESET;
	assert(a->getName() == "RobotomyRequestForm");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Constructor Call's Name correct\n" << RESET;
	assert(a->getTarget() == "RRF");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Constructor Call's Target correct\n" << RESET;
	assert(a->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Constructor Call's IsSign correct\n" << RESET;
	assert(a->getSignGrade() == 72);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Constructor Call's SignGrade correct\n" << RESET;
	assert(a->getExecGrade() == 45);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Constructor Call's ExecuteGrade correct\n" << RESET;

	delete a;
}

void testShrubberyCreationFormDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm *a = new ShrubberyCreationForm();

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Default Constructor Call's Message correct\n" << RESET;
	assert(a->getName() == "ShrubberyCreationForm");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Constructor Call's Name correct\n" << RESET;
	assert(a->getTarget() == "SCF");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Constructor Call's Target correct\n" << RESET;
	assert(a->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Constructor Call's IsSign correct\n" << RESET;
	assert(a->getSignGrade() == 145);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Constructor Call's SignGrade correct\n" << RESET;
	assert(a->getExecGrade() == 137);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Constructor Call's ExecuteGrade correct\n" << RESET;

	delete a;
}

void testPresidentialPardonFormTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm *b = new PresidentialPardonForm("PPF");

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's Message correct\n" << RESET;
	assert(b->getName() == "PresidentialPardonForm");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's Name correct\n" << RESET;
	assert(b->getTarget() == "PPF");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's Target correct\n" << RESET;
	assert(b->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's IsSign correct\n" << RESET;
	assert(b->getSignGrade() == 25);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's SignGrade correct\n" << RESET;
	assert(b->getExecGrade() == 5);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Target Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
}

void testRobotomyRequestFormTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm *b = new RobotomyRequestForm("RRF");

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's Message correct\n" << RESET;
	assert(b->getName() == "RobotomyRequestForm");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's Name correct\n" << RESET;
	assert(b->getTarget() == "RRF");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's Target correct\n" << RESET;
	assert(b->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's IsSign correct\n" << RESET;
	assert(b->getSignGrade() == 72);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's SignGrade correct\n" << RESET;
	assert(b->getExecGrade() == 45);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Target Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
}

void testShrubberyCreationFormTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm *b = new ShrubberyCreationForm("SCF");

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's Message correct\n" << RESET;
	assert(b->getName() == "ShrubberyCreationForm");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's Name correct\n" << RESET;
	assert(b->getTarget() == "SCF");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's Target correct\n" << RESET;
	assert(b->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's IsSign correct\n" << RESET;
	assert(b->getSignGrade() == 145);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's SignGrade correct\n" << RESET;
	assert(b->getExecGrade() == 137);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Target Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
}

void testPresidentialPardonFormCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm *b = new PresidentialPardonForm("PPF");
	PresidentialPardonForm *c = new PresidentialPardonForm(*b);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's Message correct\n" << RESET;
	assert(c->getName() == "PresidentialPardonForm");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's Name correct\n" << RESET;
	assert(c->getTarget() == "PPF");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's Target correct\n" << RESET;
	assert(c->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's IsSign correct\n" << RESET;
	assert(c->getSignGrade() == 25);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's SignGrade correct\n" << RESET;
	assert(c->getExecGrade() == 5);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Copy Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
	delete c;
}

void testRobotomyRequestFormCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm *b = new RobotomyRequestForm("RRF");
	RobotomyRequestForm *c = new RobotomyRequestForm(*b);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's Message correct\n" << RESET;
	assert(c->getName() == "RobotomyRequestForm");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's Name correct\n" << RESET;
	assert(c->getTarget() == "RRF");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's Target correct\n" << RESET;
	assert(c->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's IsSign correct\n" << RESET;
	assert(c->getSignGrade() == 72);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's SignGrade correct\n" << RESET;
	assert(c->getExecGrade() == 45);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Copy Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
	delete c;
}

void testShrubberyCreationFormCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm *b = new ShrubberyCreationForm("SCF");
	ShrubberyCreationForm *c = new ShrubberyCreationForm(*b);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's Message correct\n" << RESET;
	assert(c->getName() == "ShrubberyCreationForm");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's Name correct\n" << RESET;
	assert(c->getTarget() == "SCF");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's Target correct\n" << RESET;
	assert(c->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's IsSign correct\n" << RESET;
	assert(c->getSignGrade() == 145);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's SignGrade correct\n" << RESET;
	assert(c->getExecGrade() == 137);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Copy Constructor Call's ExecuteGrade correct\n" << RESET;

	delete b;
	delete c;
}

void testPresidentialPardonFormAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm *c = new PresidentialPardonForm("PPF");
	PresidentialPardonForm *d = new PresidentialPardonForm();

	*d = *c;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's Message correct\n" << RESET;
	assert(d->getName() == "PresidentialPardonForm");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's Name correct\n" << RESET;
	assert(d->getTarget() == "PPF");
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's Target correct\n" << RESET;
	assert(d->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's IsSign correct\n" << RESET;
	assert(d->getSignGrade() == 25);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's SignGrade correct\n" << RESET;
	assert(d->getExecGrade() == 5);
	std::cout << GREEN << "   " << "\u2714" << " PresidentialPardonForm Assignment Operator Call's ExecuteGrade correct\n" << RESET;

	delete c;
	delete d;
}

void testRobotomyRequestFormAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm *c = new RobotomyRequestForm("RRF");
	RobotomyRequestForm *d = new RobotomyRequestForm();

	*d = *c;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's Message correct\n" << RESET;
	assert(d->getName() == "RobotomyRequestForm");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's Name correct\n" << RESET;
	assert(d->getTarget() == "RRF");
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's Target correct\n" << RESET;
	assert(d->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's IsSign correct\n" << RESET;
	assert(d->getSignGrade() == 72);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's SignGrade correct\n" << RESET;
	assert(d->getExecGrade() == 45);
	std::cout << GREEN << "   " << "\u2714" << " RobotomyRequestForm Assignment Operator Call's ExecuteGrade correct\n" << RESET;

	delete c;
	delete d;
}

void testShrubberyCreationFormAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm *c = new ShrubberyCreationForm("SCF");
	ShrubberyCreationForm *d = new ShrubberyCreationForm();

	*d = *c;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's Message correct\n" << RESET;
	assert(d->getName() == "ShrubberyCreationForm");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's Name correct\n" << RESET;
	assert(d->getTarget() == "SCF");
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's Target correct\n" << RESET;
	assert(d->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's IsSign correct\n" << RESET;
	assert(d->getSignGrade() == 145);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's SignGrade correct\n" << RESET;
	assert(d->getExecGrade() == 137);
	std::cout << GREEN << "   " << "\u2714" << " ShrubberyCreationForm Assignment Operator Call's ExecuteGrade correct\n" << RESET;

	delete c;
	delete d;
}

void testPresidentialPardonFormInsertionOperatorforDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm l = PresidentialPardonForm();

	std::cout << l;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : PresidentialPardonForm\nAForm is signed : No\nAForm sign grade : 25\nAForm exec grade : 5\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Default Constructor\n" << RESET;
}

void testRobotomyRequestFormInsertionOperatorforDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm l = RobotomyRequestForm();

	std::cout << l;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : RobotomyRequestForm\nAForm is signed : No\nAForm sign grade : 72\nAForm exec grade : 45\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Default Constructor\n" << RESET;
}

void testShrubberyCreationFormInsertionOperatorforDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm l = ShrubberyCreationForm();

	std::cout << l;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : ShrubberyCreationForm\nAForm is signed : No\nAForm sign grade : 145\nAForm exec grade : 137\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Default Constructor\n" << RESET;
}

void testPresidentialPardonFormInsertionOperatorforTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm m = PresidentialPardonForm("person");

	std::cout << m;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : PresidentialPardonForm\nAForm is signed : No\nAForm sign grade : 25\nAForm exec grade : 5\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Target Constructor\n" << RESET;	
}

void testRobotomyRequestFormInsertionOperatorforTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm n = RobotomyRequestForm("person");

	std::cout << n;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : RobotomyRequestForm\nAForm is signed : No\nAForm sign grade : 72\nAForm exec grade : 45\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Target Constructor\n" << RESET;
}

void testShrubberyCreationFormInsertionOperatorforTargetConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm o = ShrubberyCreationForm("person");

	std::cout << o;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm name : ShrubberyCreationForm\nAForm is signed : No\nAForm sign grade : 145\nAForm exec grade : 137\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Target Constructor\n" << RESET;
}

void testPresidentialPardonFormInsertionOperatorforCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm a = PresidentialPardonForm("person");
	PresidentialPardonForm b = PresidentialPardonForm(a);

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\nAForm name : PresidentialPardonForm\nAForm is signed : No\nAForm sign grade : 25\nAForm exec grade : 5\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testRobotomyRequestFormInsertionOperatorforCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm a = RobotomyRequestForm("person");
	RobotomyRequestForm b = RobotomyRequestForm(a);

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\nAForm name : RobotomyRequestForm\nAForm is signed : No\nAForm sign grade : 72\nAForm exec grade : 45\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testShrubberyCreationFormInsertionOperatorforCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm a = ShrubberyCreationForm("person");
	ShrubberyCreationForm b = ShrubberyCreationForm(a);

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm Copy constructor called\nAForm name : ShrubberyCreationForm\nAForm is signed : No\nAForm sign grade : 145\nAForm exec grade : 137\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testPresidentialPardonFormInsertionOperatorforAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	PresidentialPardonForm a = PresidentialPardonForm("person");
	PresidentialPardonForm b;

	b = a;

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\nAForm name : PresidentialPardonForm\nAForm is signed : No\nAForm sign grade : 25\nAForm exec grade : 5\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testRobotomyRequestFormInsertionOperatorforAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	RobotomyRequestForm a = RobotomyRequestForm("person");
	RobotomyRequestForm b;

	b = a;

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\nAForm name : RobotomyRequestForm\nAForm is signed : No\nAForm sign grade : 72\nAForm exec grade : 45\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Assignment Operator\n" << RESET;
}

void testShrubberyCreationFormInsertionOperatorforAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	ShrubberyCreationForm a = ShrubberyCreationForm("person");
	ShrubberyCreationForm b;

	b = a;

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "AForm constructor called\nAForm constructor called\nAForm Assignment operator called\nAForm name : ShrubberyCreationForm\nAForm is signed : No\nAForm sign grade : 145\nAForm exec grade : 137\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Assignment Operator\n" << RESET;
}

void testPresidentialPardonFormSignGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		PresidentialPardonForm f = PresidentialPardonForm("person");
		Bureaucrat b = Bureaucrat("person", 25);

		b.signForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed PresidentialPardonForm\n";
		assert(buffer.str() == expectedOutput);
		assert(f.getIsSign() == true);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testRobotomyRequestFormSignGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		RobotomyRequestForm f = RobotomyRequestForm("person");
		Bureaucrat b = Bureaucrat("person", 72);
		
		b.signForm(f);
		
		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed RobotomyRequestForm\n";
		assert(buffer.str() == expectedOutput);
		assert(f.getIsSign() == true);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testShrubberyCreationFormSignGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		ShrubberyCreationForm f = ShrubberyCreationForm("person");
		Bureaucrat b = Bureaucrat("person", 145);

		b.signForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed ShrubberyCreationForm\n";
		assert(buffer.str() == expectedOutput);
		assert(f.getIsSign() == true);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testPresidentialPardonFormSignGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		PresidentialPardonForm f = PresidentialPardonForm("person");
		Bureaucrat b = Bureaucrat("person", 26);

		b.signForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't sign PresidentialPardonForm because Bureaucrat's Grade is too low to sign Form\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade Too Low\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testRobotomyRequestFormSignGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		RobotomyRequestForm f = RobotomyRequestForm("person");
		Bureaucrat b = Bureaucrat("person", 73);

		b.signForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't sign RobotomyRequestForm because Bureaucrat's Grade is too low to sign Form\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade Too Low\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testShrubberyCreationFormSignGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		ShrubberyCreationForm f = ShrubberyCreationForm("person");
		Bureaucrat b = Bureaucrat("person", 146);

		b.signForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't sign ShrubberyCreationForm because Bureaucrat's Grade is too low to sign Form\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade Too Low\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testPresidentialPardonFormExecGradeInRangeAndSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		PresidentialPardonForm f = PresidentialPardonForm("person");
		Bureaucrat b = Bureaucrat("person", 5);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed PresidentialPardonForm\nperson has been pardoned by Zaphod Beeblebrox.\nperson executed PresidentialPardonForm\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testPresidentialPardonFormExecGradeInRangeAndNotSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		PresidentialPardonForm f = PresidentialPardonForm("person");
		Bureaucrat b = Bureaucrat("person", 5);

		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't execute PresidentialPardonForm because Form is not signed\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Not Signed\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testPresidentialPardonFormExecGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		PresidentialPardonForm f = PresidentialPardonForm("person");
		Bureaucrat b = Bureaucrat("person", 20);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed PresidentialPardonForm\nperson couldn't execute PresidentialPardonForm because Grade of PresidentialPardonForm is too high to execute\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade Too Low\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testRobotomyRequestFormExecGradeInRangeAndSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		RobotomyRequestForm f = RobotomyRequestForm("person");
		Bureaucrat b = Bureaucrat("person", 45);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput1 = "AForm constructor called\nBureaucrat constructor called\nperson signed RobotomyRequestForm\nperson has been robotomized successfully.\nperson executed RobotomyRequestForm\n";
		std::string expectedOutput2 = "AForm constructor called\nBureaucrat constructor called\nperson signed RobotomyRequestForm\nperson robotomization failed.\nperson executed RobotomyRequestForm\n";
		assert(buffer.str() == expectedOutput1 || buffer.str() == expectedOutput2);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testRobotomyRequestFormExecGradeInRangeAndNotSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		RobotomyRequestForm f = RobotomyRequestForm("person");
		Bureaucrat b = Bureaucrat("person", 45);

		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't execute RobotomyRequestForm because Form is not signed\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Not Signed\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testRobotomyRequestFormExecGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		RobotomyRequestForm f = RobotomyRequestForm("person");
		Bureaucrat b = Bureaucrat("person", 50);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed RobotomyRequestForm\nperson couldn't execute RobotomyRequestForm because Grade of RobotomyRequestForm is too high to execute\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade Too Low\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testShrubberyCreationFormExecGradeInRangeAndSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		ShrubberyCreationForm f = ShrubberyCreationForm("person");
		Bureaucrat b = Bureaucrat("person", 137);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed ShrubberyCreationForm\nperson_shrubbery has been created\nperson executed ShrubberyCreationForm\n";
		std::remove("person_shrubbery");
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Sign Grade In Range\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testShrubberyCreationFormExecGradeInRangeAndNotSigned() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		ShrubberyCreationForm f = ShrubberyCreationForm("person");
		Bureaucrat b = Bureaucrat("person", 137);

		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson couldn't execute ShrubberyCreationForm because Form is not signed\n";
		std::remove("person_shrubbery");
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Not Signed\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

void testShrubberyCreationFormExecGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		ShrubberyCreationForm f = ShrubberyCreationForm("person");
		Bureaucrat b = Bureaucrat("person", 140);

		b.signForm(f);
		b.executeForm(f);

		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "AForm constructor called\nBureaucrat constructor called\nperson signed ShrubberyCreationForm\nperson couldn't execute ShrubberyCreationForm because Grade of AForm too low\n";
		std::remove("person_shrubbery");
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Exec Grade In Range and Not Signed\n" << RESET;
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
}

int main(void) {
	std::cout << GREEN << "\n\n<< Bureaucat Test >>\n\n" << RESET;
		std::cout << "\n\nConstructor Call Test\n\n";
	{
		std::cout << "\n[Test1.1.1] DefaultConstructor\n";
		testBureaucratDefaultConstructor();
		std::cout << "\n[Test1.1.2] Grade Overload Constructor\n";
		testBureaucratGradeConstructor();
		std::cout << "\n[Test1.1.3] Name Overload Constructor\n";
		testBureaucratNameConstructor();
		std::cout << "\n[Test1.1.4] Constructor\n";
		testBureaucratNameGradeConstructor();
		std::cout << "\n[Test1.1.5] Copy Constructor\n";
		testBureaucratCopyConstructor();
		std::cout << "\n[Test1.1.6] Assignment Operator\n";
		testBureaucratAssignmentOperator();
	}
		std::cout << "\n\nGrade Exception Test\n\n";
	{
		std::cout << "\n[Test1.2.1] Grade below than 1 should return GradeTooHighException\n";
		testGradeBelowOne();
		std::cout << "\n[Test1.2.2] Grade range from 1 to 150 should not throw any exception\n";
		testGradeOnetoOneHundredFifty();
		std::cout << "\n[Test1.2.3] Grade greater than 150 should return GradeTooLowException\n";
		testGradeOverOneHundredFifty();
	}
		std::cout << "\n\nIncrement/Decrement Test\n\n";
	{
		std::cout << "\n[Test1.3.1] Increment Test\n";
		testIncrementWithGradeOne();
		testIncrementWithGradeInRange();
		std::cout << "\n[Test1.3.2] Decrement Test\n";
		testDecrementWithGradeOneHundredFifty();
		testDecrementWithGradeInRange();
	}
		std::cout << "\n\nInsertion Operator Test\n\n";
	{
		std::cout << "\n[Test1.4.1] Insertion Operator Test\n";
		testInsertionOperatorforDefaultConstructor();
		testInsertionOperatorforGradeConstructor();
		testInsertionOperatorforNameConstructor();
		testInsertionOperatorforNameGradeConstructor();
		testInsertionOperatorforCopyConstructor();
		testInsertionOperatorforAssignmentOperator();
	}
		std::cout << GREEN << "\n\n<< AForm Test >>\n\n" << RESET;
		std::cout << "\n\nAForm Constructor Call Test\n\n";
	{
		std::cout << "\n[Test2.1.1] PresidentialPardonForm Default Constructor Test\n";
		testPresidentialPardonFormDefaultConstructor();
		std::cout << "\n[Test2.1.2] RobotomyRequestForm Default Constructor Test\n";
		testRobotomyRequestFormDefaultConstructor();
		std::cout << "\n[Test2.1.3] ShrubberyCreationForm Default Constructor Test\n";
		testShrubberyCreationFormDefaultConstructor();
		std::cout << "\n[Test2.2.1] PresidentialPardonForm target Constructor Test\n";
		testPresidentialPardonFormTargetConstructor();
		std::cout << "\n[Test2.2.2] RobotomyRequestForm target Constructor Test\n";
		testRobotomyRequestFormTargetConstructor();
		std::cout << "\n[Test2.2.3] ShrubberyCreationForm target Constructor Test\n";
		testShrubberyCreationFormTargetConstructor();
		std::cout << "\n[Test2.3.1] PresidentialPardonForm Copy Constructor Test\n";
		testPresidentialPardonFormCopyConstructor();
		std::cout << "\n[Test2.3.2] RobotomyRequestForm Copy Constructor Test\n";
		testRobotomyRequestFormCopyConstructor();
		std::cout << "\n[Test2.3.3] ShrubberyCreationForm Copy Constructor Test\n";
		testShrubberyCreationFormCopyConstructor();
		std::cout << "\n[Test2.4.1] PresidentialPardonForm Assignment Operator Test\n";
		testPresidentialPardonFormAssignmentOperator();
		std::cout << "\n[Test2.4.2] RobotomyRequestForm Assignment Operator Test\n";
		testRobotomyRequestFormAssignmentOperator();
		std::cout << "\n[Test2.4.3] ShrubberyCreationForm Assignment Operator Test\n";
		testShrubberyCreationFormAssignmentOperator();
	}
		std::cout << "\n\nAForm Insertion Operator Test\n\n";
	{
		std::cout << "\n[Test2.5.1] PresidentialPardonForm Insertion Operator Test\n";
		testPresidentialPardonFormInsertionOperatorforDefaultConstructor();
		testPresidentialPardonFormInsertionOperatorforTargetConstructor();
		testPresidentialPardonFormInsertionOperatorforCopyConstructor();
		testPresidentialPardonFormInsertionOperatorforAssignmentOperator();
		std::cout << "\n[Test2.5.2] RobotomyRequestForm Insertion Operator Test\n";
		testRobotomyRequestFormInsertionOperatorforDefaultConstructor();
		testRobotomyRequestFormInsertionOperatorforTargetConstructor();
		testRobotomyRequestFormInsertionOperatorforCopyConstructor();
		testRobotomyRequestFormInsertionOperatorforAssignmentOperator();
		std::cout << "\n[Test2.5.3] ShrubberyCreationForm Insertion Operator Test\n";
		testShrubberyCreationFormInsertionOperatorforDefaultConstructor();
		testShrubberyCreationFormInsertionOperatorforTargetConstructor();
		testShrubberyCreationFormInsertionOperatorforCopyConstructor();
		testShrubberyCreationFormInsertionOperatorforAssignmentOperator();
	}
		std::cout << "\n\nAForm Sign Test\n\n";
	{
		std::cout << "\n[Test2.6.1] PresidentialPardonForm Sign Test\n";
		testPresidentialPardonFormSignGradeInRange();
		testPresidentialPardonFormSignGradeTooLow();
		std::cout << "\n[Test2.6.2] RobotomyRequestForm Sign Test\n";
		testRobotomyRequestFormSignGradeInRange();
		testRobotomyRequestFormSignGradeTooLow();
		std::cout << "\n[Test2.6.3] ShrubberyCreationForm Sign Test\n";
		testShrubberyCreationFormSignGradeInRange();
		testShrubberyCreationFormSignGradeTooLow();
	}
		std::cout << "\n\nAForm Execute Test\n\n";
	{
		std::cout << "\n[Test2.6.1] PresidentialPardonForm Execute Test\n";
		testPresidentialPardonFormExecGradeInRangeAndSigned();
		testPresidentialPardonFormExecGradeInRangeAndNotSigned();
		testPresidentialPardonFormExecGradeTooLow();
		std::cout << "\n[Test2.6.2] RobotomyRequestForm Execute Test\n";
		testRobotomyRequestFormExecGradeInRangeAndSigned();
		testRobotomyRequestFormExecGradeInRangeAndNotSigned();
		testRobotomyRequestFormExecGradeTooLow();
		std::cout << "\n[Test2.6.3] ShrubberyCreationForm Execute Test\n";
		testShrubberyCreationFormExecGradeInRangeAndSigned();
		testShrubberyCreationFormExecGradeInRangeAndNotSigned();
		testShrubberyCreationFormExecGradeTooLow();
	}
	return 0;
}