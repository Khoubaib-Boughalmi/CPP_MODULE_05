#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "AForm.h"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat& other);
        const Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
        virtual const std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif