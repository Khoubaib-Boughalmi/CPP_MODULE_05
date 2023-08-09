#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 10);
		RobotomyRequestForm robot("Boting");
		bureaucrat1.signForm(robot);
		// shrubbery.execute(bureaucrat1);
		bureaucrat1.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}