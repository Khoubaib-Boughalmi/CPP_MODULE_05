#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.h"
#include <fstream>

class Bureaucrat;

class AForm{
    private:
        const std::string   _name;
        bool                _signed;
        int const           _reqSignGrade;
        int const           _reqExecuteGrade;
    public:
        AForm();
        AForm(std::string name, const int reqSignGrade, const int reqExecuteGrade);
        AForm(const AForm& other);
        const AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string getName(void) const;
        bool getSigned(void) const;
        int getReqSignGrade(void) const;
        int getReqExecuteGrade(void) const; 
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        int check_permissions(Bureaucrat const & executor) const;
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
        class FormNotSignedException: public std::exception {
            public:
                const char* what() const throw();
        };
        class OpenFileException: public std::exception {
            public:
                const char* what() const throw();
        };
       
};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif