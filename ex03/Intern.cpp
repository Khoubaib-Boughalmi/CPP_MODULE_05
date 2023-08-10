#include "Intern.h"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

const Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return (*this);
}

const char *Intern::InterDataException::what() const throw(){
    return "Error: InterDataException";
}
const char *Intern::InterFormCreationException::what() const throw(){
    return "Error: InterFormCreationException";
}

AForm* Intern::PresidentialPardonFormInstantiation(std::string targer) {
    return new PresidentialPardonForm(targer);
}
AForm* Intern::RobotomyRequestFormInstantiation(std::string targer)  {
    return new RobotomyRequestForm(targer);
}
AForm* Intern::ShrubberyCreationFormInstantiation(std::string targer)  {
    return new ShrubberyCreationForm(targer);
}

AForm* Intern::makeForm(std::string name, std::string target) {
    AForm *form = NULL;

    AForm* (Intern::*ptrFun[4])(std::string target) = {&Intern::PresidentialPardonFormInstantiation, \
    &Intern::RobotomyRequestFormInstantiation, &Intern::ShrubberyCreationFormInstantiation};

    std::string formList[3] = {
        "presidential request",
        "robotomy request",
        "Shrubbery request"
    };
    int idx = -1;
    for (int i = 0; i < 3; i++)
    {
        if(formList[i] == name)
        {
            idx = i;
           form = (this->*ptrFun[i])(target);
            break;
        }
    }
    if(idx == -1)
        throw InterFormCreationException();
    std::cout << "Intern creates " << form->getName() << std::endl;
    return (form);
}
