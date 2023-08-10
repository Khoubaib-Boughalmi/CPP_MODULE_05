#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName()) {
    *this = other;
}
const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if(this != &other)
        this->_grade = other.getGrade();
    return (*this);
}

const std::string Bureaucrat::getName() const {
    return this->_name;
}
int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    this->_grade--;
    if(getGrade() < 1)
        throw GradeTooHighException();
}
void Bureaucrat::decrementGrade() {
    this->_grade++;
    if(getGrade() > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Error: GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Error: GradeTooLowException";
}

void Bureaucrat::signForm(AForm &aform) {
    try
    {
        aform.beSigned(*this);
        std::cout << this->getName() << " signed " << aform.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;	
    }
    catch(const std::exception& e)
    {
        std::cout << "Couldn't execute this form because "<< e.what() << std::endl;
    }
}


Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << " bureaucrat grad " << obj.getGrade();
    return os;
}
