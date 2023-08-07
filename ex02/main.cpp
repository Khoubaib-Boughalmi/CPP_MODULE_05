#include "Bureaucrat.h"
#include "AForm.h"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat1("snape", 1);

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}