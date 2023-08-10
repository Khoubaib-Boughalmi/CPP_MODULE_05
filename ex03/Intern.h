#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class AForm;

class Intern
{
    private:
      
    public:
        Intern();
        Intern(const Intern& other);
        const Intern& operator=(const Intern& other);
        virtual ~Intern();
        AForm* makeForm(std::string name, std::string target);
        AForm *PresidentialPardonFormInstantiation(std::string targer);
        AForm *RobotomyRequestFormInstantiation(std::string targer);
        AForm *ShrubberyCreationFormInstantiation(std::string targer);
        class InterDataException: public std::exception {
            public:
                const char* what() const throw();
        };
        class InterFormCreationException: public std::exception {
            public:
                const char* what() const throw();
        };
       
};

#endif