#include "Bureaucrat.h"
#include "Form.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 1);
		Form		form1("slytherin common room", 3, 6);

		std::cout << form1 << std::endl;

		form1.beSigned(bureaucrat1);

		std::cout << form1 << std::endl;
		form1.beSigned(bureaucrat1);
		std::cout << form1 << std::endl; // won't execute
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	bureaucrat1("Malfoy", 150); // too low grade permissions
		Form		form1("slytherin Library", 1, 6);

		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);

		std::cout << form1 << std::endl;
		form1.beSigned(bureaucrat1);
		std::cout << form1 << std::endl; // won't execute
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
