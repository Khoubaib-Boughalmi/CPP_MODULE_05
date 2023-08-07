#include "AForm.h"

AForm::AForm():  _name("Default"),_reqSignGrade(150),_reqExecuteGrade(150){}

AForm::AForm(std::string name, const int reqSignGrade, const int reqExecuteGrade): _name(name), _reqSignGrade(reqSignGrade), _reqExecuteGrade(reqExecuteGrade){
    if(_reqExecuteGrade < 1 || _reqSignGrade < 1)
        throw GradeTooHighException();
    if(_reqExecuteGrade > 150 || _reqSignGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other): _name(other.getName()), _reqSignGrade(other.getReqSignGrade()), _reqExecuteGrade(other.getReqExecuteGrade()) {
    *this = other;
}
const AForm& AForm::operator=(const AForm& other) {
    if(this != &other)
        this->_signed = other.getSigned();
    return (*this);
}

const std::string AForm::getName() const {
    return this->_name;
}
bool AForm::getSigned() const {
    return this->_signed;
}
int AForm::getReqSignGrade() const {
    return this->_reqSignGrade;
}
int AForm::getReqExecuteGrade() const {
    return this->_reqExecuteGrade;
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Error: GradeTooHighException";
}
const char *AForm::GradeTooLowException::what() const throw(){
    return "Error: GradeTooLowException";
}
const char *AForm::FormAlreadySignedException::what() const throw(){
    return "Error: AFormAlreadySignedException";
}
const char *AForm::OpenFileException::what() const throw(){
    return "Error: OpenFileException";
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->getReqSignGrade() && !this->getSigned())
    {
        this->_signed = 1;        
        std::cout << "Bureaucrat " << bureaucrat.getName() << " signed AForm: " << this->getName() << std::endl;
    }
    else if(bureaucrat.getGrade() > this->getReqSignGrade())
        throw GradeTooLowException();
    else
        throw FormAlreadySignedException();
}

std::ostream& operator<<(std::ostream &os, const AForm& obj) {
    os << "form: " <<  obj.getName() << " with a " << obj.getReqExecuteGrade() \
    << " Required Execute Grade" << " and a " << obj.getReqSignGrade() \
    <<  " Required Sign Grade" \
    <<(obj.getSigned() ? " has been signed" : " has not been signed") ;
    return os;
}
