#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"

class Bureaucrat;

class Form{
    private:
        const std::string   _name;
        bool                _signed;
        int const           _reqSignGrade;
        int const           _reqExecuteGrade;
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();
        };
        class FormAlreadySignedException: public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        Form();
        Form(std::string name, const int reqSignGrade, const int reqExecuteGrade);
        Form(const Form& other);
        const Form& operator=(const Form& other);
        ~Form();
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getReqSignGrade(void) const;
        int getReqExecuteGrade(void) const;
        void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &os, const Form& obj);

#endif