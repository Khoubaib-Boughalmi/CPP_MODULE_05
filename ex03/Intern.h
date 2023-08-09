#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class AForm;

class Inter
{
    private:
      
    public:
        Inter();
        Inter(const std::string name, const int grade);
        Inter(const Inter& other);
        const Inter& operator=(const Inter& other);
        virtual ~Inter();
       
};

#endif