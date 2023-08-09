#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int	main(void)
{
	{
		try {
			Bureaucrat	bureaucrat1("Kais said", 1);
			ShrubberyCreationForm shrubb("Forest");
			bureaucrat1.signForm(shrubb);
			// shrubbery.execute(bureaucrat1);
			bureaucrat1.executeForm(shrubb);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat	bureaucrat1("Kais said", 1);
			PresidentialPardonForm presedent("Neoliberal Capitalism and the Rise of Authoritarian Politics");
			bureaucrat1.signForm(presedent);
			// shrubbery.execute(bureaucrat1);
			bureaucrat1.executeForm(presedent);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat	bureaucrat1("Kais said", 1);
			PresidentialPardonForm presedent("Neoliberal Capitalism and the Rise of Authoritarian Politics");
			bureaucrat1.signForm(presedent);
			// shrubbery.execute(bureaucrat1);
			bureaucrat1.executeForm(presedent);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}