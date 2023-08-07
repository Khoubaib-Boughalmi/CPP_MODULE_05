#include "Bureaucrat.h"

int main()
{
    try {
		Bureaucrat	bureacrat1("snape", 4);

		bureacrat1.incrementGrade();
		bureacrat1.incrementGrade();
		std::cout << bureacrat1 << std::endl;

		bureacrat1.incrementGrade();
		bureacrat1.incrementGrade();
		std::cout << bureacrat1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	bureaucrat1("john doe", 149);

		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;

		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return (0);
}