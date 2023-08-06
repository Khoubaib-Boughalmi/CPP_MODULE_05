#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        const Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        std::string getName(void);
        int getGrade(void);
        void incrementGrade(int value);
        void decrementGrade(int value);
        class GradeTooHighException: public std::exception {
            public:
                GradeTooHighException();
                ~GradeTooHighException();
                const char* what(void);
        };
        class GradeTooLowException: public std::exception {
            public:
                GradeTooLowException();
                ~GradeTooLowException();
                const char* what(void);
        };
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif