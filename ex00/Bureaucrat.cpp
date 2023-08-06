#include "Bureaucrat.h"

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

const std::string Bureaucrat::getName() const {
    return this->_name;
}
int Bureaucrat::getGrade() const {
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

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Error: GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Error: GradeTooLowException";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->getName() << " with Grade of "<< this->getGrade()<< " deconstructed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << " bureaucrat grad" << obj.getGrade() << std::endl;
    return os;
}
