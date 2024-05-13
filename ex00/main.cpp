#include <iostream>
#include "Bureaucrat.hpp"

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

int main(void) {
		std::cout << "\n\nConstructor Call Test\n\n";
	{
		std::cout << "\n[Test1.1.1] DefaultConstructor\n";
		testBureaucratDefaultConstructor();
		std::cout << "\n[Test1.2.1] Grade Overload Constructor\n";
		testBureaucratGradeConstructor();
		std::cout << "\n[Test1.3.1] Name Overload Constructor\n";
		testBureaucratNameConstructor();
		std::cout << "\n[Test1.4.1] Constructor\n";
		testBureaucratNameGradeConstructor();
		std::cout << "\n[Test1.5.1] Copy Constructor\n";
		testBureaucratCopyConstructor();
		std::cout << "\n[Test1.6.1] Assignment Operator\n";
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
		std::cout << "\n\n";
}