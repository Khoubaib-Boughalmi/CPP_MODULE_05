#include "Bureaucrat.h"
#include "AForm.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 1);
		AForm		form1("slytherin common room", 3, 6);

		std::cout << form1 << std::endl;

		form1.beSigned(bureaucrat1);

		std::cout << form1 << std::endl;
		form1.beSigned(bureaucrat1);
		std::cout << form1 << std::endl; // won't execute
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}