#include "Intern.h"
int	main(void)
{
	{
			Bureaucrat bureaucrat1("kais said", 1);
			AForm *form;
			Intern cleverInter;
			try
			{
				form = cleverInter.makeForm("robotomy request", "MR.Robotomy");
				bureaucrat1.signForm(*form);
				bureaucrat1.executeForm(*form);
				delete form;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
	}
	return (0);
}