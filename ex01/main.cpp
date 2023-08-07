#include "Bureaucrat.h"

int main()
{
    try {
		Bureaucrat	man1("bob", 3);

		man1.incrementGrade();
		man1.incrementGrade();
		std::cout << man1 << std::endl;

		man1.incrementGrade();
		man1.incrementGrade();
		std::cout << man1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	man2("jim", 149);

		man2.decrementGrade();
		std::cout << man2 << std::endl;

		man2.decrementGrade();
		std::cout << man2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return (0);
}