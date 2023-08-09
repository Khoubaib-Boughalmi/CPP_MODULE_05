#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 144);
		ShrubberyCreationForm shrubbery("Forest");
		bureaucrat1.signForm(shrubbery);
		shrubbery.execute(bureaucrat1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}