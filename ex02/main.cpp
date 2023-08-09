#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 150);
		ShrubberyCreationForm shrubbery("Forest");
		bureaucrat1.signForm(shrubbery);
		// shrubbery.execute(bureaucrat1);
		bureaucrat1.executeForm(shrubbery);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}