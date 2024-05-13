#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void testFormDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *a = new Form();

	std::cout.rdbuf(oldCout);

    std::string expectedOutput = "Form default constructor called\n";
    std::string actualOutput = buffer.str();

    assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Constructor Call's Message correct\n" << RESET;
    assert(a->getName() == "form");
	std::cout << GREEN << "   " << "\u2714" << " Form Constructor Call's Name correct\n" << RESET;
    assert(a->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Constructor Call's IsSign correct\n" << RESET;
	assert(a->getSignGrade() == 30);
	std::cout << GREEN << "   " << "\u2714" << " Form Constructor Call's SignGrade correct\n" << RESET;
	assert(a->getExecGrade() == 60);
	std::cout << GREEN << "   " << "\u2714" << " Form Constructor Call's ExecGrade correct\n" << RESET;

    delete a;
}

void testFormGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *b = new Form(20, 40);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form default grade constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Grade Constructor Call's Message correct\n" << RESET;
	assert(b->getName() == "form");
	std::cout << GREEN << "   " << "\u2714" << " Form Default Grade Constructor Call's Name correct\n" << RESET;
	assert(b->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Grade Constructor Call's IsSign correct\n" << RESET;
	assert(b->getSignGrade() == 20);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Grade Constructor Call's SignGrade correct\n" << RESET;
	assert(b->getExecGrade() == 40);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Grade Constructor Call's ExecGrade correct\n" << RESET;

	delete b;
}

void testFormNameConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *c = new Form("person");

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form default name constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Constructor Call's Message correct\n" << RESET;
	assert(c->getName() == "person");
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Constructor Call's Name correct\n" << RESET;
	assert(c->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Constructor Call's IsSign correct\n" << RESET;
	assert(c->getSignGrade() == 150);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Constructor Call's SignGrade correct\n" << RESET;
	assert(c->getExecGrade() == 150);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Constructor Call's ExecGrade correct\n" << RESET;

	delete c;
}

void testFormNameGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *d = new Form("person", 20, 40);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Grade Constructor Call's Message correct\n" << RESET;
	assert(d->getName() == "person");
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Grade Constructor Call's Name correct\n" << RESET;
	assert(d->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Grade Constructor Call's IsSign correct\n" << RESET;
	assert(d->getSignGrade() == 20);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Grade Constructor Call's SignGrade correct\n" << RESET;
	assert(d->getExecGrade() == 40);
	std::cout << GREEN << "   " << "\u2714" << " Form Default Name Grade Constructor Call's ExecGrade correct\n" << RESET;

	delete d;
}

void testFormCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *e = new Form("person", 20, 40);
	Form *f = new Form(*e);

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\nForm copy constructor called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Copy Constructor Call's Message correct\n" << RESET;
	assert(f->getName() == "person");
	std::cout << GREEN << "   " << "\u2714" << " Form Copy Constructor Call's Name correct\n" << RESET;
	assert(f->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Copy Constructor Call's IsSign correct\n" << RESET;
	assert(f->getSignGrade() == 20);
	std::cout << GREEN << "   " << "\u2714" << " Form Copy Constructor Call's SignGrade correct\n" << RESET;
	assert(f->getExecGrade() == 40);
	std::cout << GREEN << "   " << "\u2714" << " Form Copy Constructor Call's ExecGrade correct\n" << RESET;

	delete e;
	delete f;
}

void testFormAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form *g = new Form("person", 20, 40);
	Form *h = new Form();

	*h = *g;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\nForm default constructor called\nForm Assignment operator called\n";
	std::string actualOutput = buffer.str();

	assert(actualOutput == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Form Assignment Operator Call's Message correct\n" << RESET;
	assert(h->getName() == "form");
	std::cout << GREEN << "   " << "\u2714" << " Form Assignment Operator Call's Name correct\n" << RESET;
	assert(h->getIsSign() == false);
	std::cout << GREEN << "   " << "\u2714" << " Form Assignment Operator Call's IsSign correct\n" << RESET;
	assert(h->getSignGrade() == 30);
	std::cout << GREEN << "   " << "\u2714" << " Form Assignment Operator Call's SignGrade correct\n" << RESET;
	assert(h->getExecGrade() == 60);
	std::cout << GREEN << "   " << "\u2714" << " Form Assignment Operator Call's ExecGrade correct\n" << RESET;

	delete g;
}

void testFormGradeBelowOne() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Form *i = new Form("person", 0, 40);
		std::cout.rdbuf(oldCout);
		assert(false && "Exception not thrown");
	} catch (std::exception & e) {
		std::string expectedOutput = "Grade of Form too high";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " GradeTooHighException's message correct\n" << RESET;
	}
}

void testFormGradeOnetoOneHundredFifty() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Form *j = new Form("person", 150, 40);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " Test passed with no exception\n" << RESET;
	} catch (std::exception &e) {
		assert(false && "this condition should not thrown");
	}
}

void testFormGradeOverOneHundredFifty() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Form *k = new Form("person", 151, 40);
		std::cout.rdbuf(oldCout);
		assert(false && "Exception not thrown");
	} catch (std::exception & e) {
		std::string expectedOutput = "Grade of Form too low";
		assert(e.what() == expectedOutput);
		std::cout.rdbuf(oldCout);
		std::cout << GREEN << "   " << "\u2714" << " GradeTooLowException's message correct\n" << RESET;
	}
}

void testFormInsertionOperatorforDefaultConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form l = Form();

	std::cout << l;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form default constructor called\nForm name : form\nForm is signed : No\nForm sign grade : 30\nForm exec grade : 60\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Default Constructor\n" << RESET;
}

void testFormInsertionOperatorforGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form m = Form(20, 40);

	std::cout << m;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form default grade constructor called\nForm name : form\nForm is signed : No\nForm sign grade : 20\nForm exec grade : 40\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Grade Constructor\n" << RESET;
}

void testFormInsertionOperatorforNameConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form n = Form("person");

	std::cout << n;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form default name constructor called\nForm name : person\nForm is signed : No\nForm sign grade : 150\nForm exec grade : 150\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Name Constructor\n" << RESET;
}

void testFormInsertionOperatorforNameGradeConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form o = Form("person", 20, 40);

	std::cout << o;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\nForm name : person\nForm is signed : No\nForm sign grade : 20\nForm exec grade : 40\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Name and Grade Constructor\n" << RESET;
}

void testFormInsertionOperatorforCopyConstructor() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form a = Form("person", 20, 40);
	Form b = Form(a);

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\nForm copy constructor called\nForm name : person\nForm is signed : No\nForm sign grade : 20\nForm exec grade : 40\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Copy Constructor\n" << RESET;
}

void testFormInsertionOperatorforAssignmentOperator() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	Form a = Form("person", 20, 40);
	Form b;

	b = a;

	std::cout << b;

	std::cout.rdbuf(oldCout);

	std::string expectedOutput = "Form constructor called\nForm default constructor called\nForm Assignment operator called\nForm name : form\nForm is signed : No\nForm sign grade : 30\nForm exec grade : 60\n";
	assert(buffer.str() == expectedOutput);
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Assignment Operator\n" << RESET;
}

void testFormSignGradeInRange() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Form f = Form("person", 20, 40);
		Bureaucrat b = Bureaucrat("person", 17);

		b.signForm(f);

		std::cout.rdbuf(oldCout);
		assert(f.getIsSign() == true);
	} catch (std::exception& e) {
		assert(false && "should not thrown an exception");
	}
	std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade In Range\n" << RESET;
}

void testFormSignGradeTooLow() {
	std::stringstream buffer;
	std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

	try {
		Form f = Form("form", 20, 40);
		Bureaucrat b = Bureaucrat("person", 21);

		b.signForm(f);
		std::cout.rdbuf(oldCout);

		std::string expectedOutput = "Form constructor called\nBureaucrat constructor called\nperson couldn't sign form because Bureaucrat's Grade is too low to sign Form\n";
		assert(buffer.str() == expectedOutput);
		std::cout << GREEN << "   " << "\u2714" << " Test passed for Sign Grade Too Low\n" << RESET;

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
		std::cout << GREEN << "\n\n<< Form Test >>\n\n" << RESET;
		std::cout << "\n\nConstructor Call Test\n\n";
	{
		std::cout << "\n[Test2.1.1] Form DefaultConstructor\n";
		testFormDefaultConstructor();
		std::cout << "\n[Test2.1.2] Form Grade Overload Constructor\n";
		testFormGradeConstructor();
		std::cout << "\n[Test2.1.3] Form Name Overload Constructor\n";
		testFormNameConstructor();
		std::cout << "\n[Test2.1.4] Form Constructor\n";
		testFormNameGradeConstructor();
		std::cout << "\n[Test2.1.5] Form Copy Constructor\n";
		testFormCopyConstructor();
		std::cout << "\n[Test2.1.6] Form Assignment Operator\n";
		testFormAssignmentOperator();
	}
		std::cout << "\n\nGrade Exception Test\n\n";
	{
		std::cout << "\n[Test2.2.1] Grade below than 1 should return GradeTooHighException\n";
		testFormGradeBelowOne();
		std::cout << "\n[Test2.2.2] Grade range from 1 to 150 should not throw any exception\n";
		testFormGradeOnetoOneHundredFifty();
		std::cout << "\n[Test2.2.3] Grade greater than 150 should return GradeTooLowException\n";
		testFormGradeOverOneHundredFifty();
	}
		std::cout << "\n\nInsertion Operator Test\n\n";
	{
		std::cout << "\n[Test2.3.1] For Insertion Operator Test for Default Constructor\n";
		testFormInsertionOperatorforDefaultConstructor();
		testFormInsertionOperatorforGradeConstructor();
		testFormInsertionOperatorforNameConstructor();
		testFormInsertionOperatorforNameGradeConstructor();
		testFormInsertionOperatorforCopyConstructor();
		testFormInsertionOperatorforAssignmentOperator();
	}
		std::cout << "\n\nSign Test\n\n";
	{
		std::cout << "\n[Test2.4.1] Form beSigned() and signForm() Test\n";
		testFormSignGradeInRange();
		testFormSignGradeTooLow();
	}
		std::cout << "\n\n";
	return 0;
}