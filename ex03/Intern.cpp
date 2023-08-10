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

AForm* Intern::makeForm(std::string name, std::string target) {
    AForm *form = NULL;

    if(name.empty() || target.empty())
        throw InterDataException();
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
            break;
        }
    }
    if(idx == -1)
        throw InterFormCreationException();
    
    switch (idx)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
    }
    std::cout << "Intern creates" << form->getName();
    return (form);
}
