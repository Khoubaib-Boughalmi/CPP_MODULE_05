#include "Form.h"

Form::Form(): _name("Default"), _signed(0), _reqSignGrade(150), _reqExecuteGrade(150){}

Form::Form(std::string name, const int reqSignGrade, const int reqExecuteGrade): _name(name), _signed(0), _reqSignGrade(reqSignGrade), _reqExecuteGrade(reqExecuteGrade){
    if(_reqExecuteGrade < 1 || _reqSignGrade < 1)
        throw GradeTooHighException();
    if(_reqExecuteGrade > 150 || _reqSignGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other): _name(other.getName()), _reqSignGrade(other.getReqSignGrade()), _reqExecuteGrade(other.getReqExecuteGrade()) {
    this->_signed = other.getSigned();
    *this = other;
}
const Form& Form::operator=(const Form& other) {
    if(this != &other)
        this->_signed = other.getSigned();
    return (*this);
}

const std::string Form::getName() const {
    return this->_name;
}
bool Form::getSigned() const {
    return this->_signed;
}
int Form::getReqSignGrade() const {
    return this->_reqSignGrade;
}
int Form::getReqExecuteGrade() const {
    return this->_reqExecuteGrade;
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Error: GradeTooHighException";
}
const char *Form::GradeTooLowException::what() const throw(){
    return "Error: GradeTooLowException";
}
const char *Form::FormAlreadySignedException::what() const throw(){
    return "Error: FormAlreadySignedException";
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->getReqSignGrade() && !this->getSigned())
    {
        this->_signed = 1;        
        std::cout << "Bureaucrat " << bureaucrat.getName() << " signed Form: " << this->getName() << std::endl;
    }
    else if(bureaucrat.getGrade() > this->getReqSignGrade())
        throw GradeTooLowException();
    else
        throw FormAlreadySignedException();
}

std::ostream& operator<<(std::ostream &os, const Form& obj) {
    os << "form: " <<  obj.getName() << " with a " << obj.getReqExecuteGrade() \
    << " Required Execute Grade" << " and a " << obj.getReqSignGrade() \
    <<  " Required Sign Grade" \
    <<(obj.getSigned() ? " has been signed" : " has not been signed") ;
    return os;
}
