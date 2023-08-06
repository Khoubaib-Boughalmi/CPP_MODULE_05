#include "Bureaucrat.h"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj;
    return os;
}

Bureaucrat::Bureaucrat(): _name("undefined"), _grade(150) {
    std::cout << "Default Constructor Called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat " << this->getName() << " with Grade of "<< this->getGrade()<< " Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = other;
}
const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Named Constructor Called" << std::endl;
    if(this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::string Bureaucrat::getName() {
    return this->_name;
}
int Bureaucrat::getGrade() {
    return this->_grade;
}

void Bureaucrat::incrementGrade(int value) {
    if(getGrade() - value < 1)
        throw GradeTooHighException();
    _grade = getGrade() - value;
}
void Bureaucrat::decrementGrade(int value) {
    if(getGrade() + value > 150)
        throw GradeTooLowException();
    _grade = getGrade() + value;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() {}

const char *Bureaucrat::GradeTooHighException::what() {
    return "Error: GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() {
    return "Error: GradeTooLowException";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->getName() << " with Grade of "<< this->getGrade()<< " deconstructed" << std::endl;
}
