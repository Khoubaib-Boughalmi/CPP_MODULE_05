#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int	main(void)
{
	{
		try {
			Bureaucrat	bureaucrat1("Kais said", 150);
			ShrubberyCreationForm shrubb("Forest");
			bureaucrat1.signForm(shrubb);
			bureaucrat1.executeForm(shrubb);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}