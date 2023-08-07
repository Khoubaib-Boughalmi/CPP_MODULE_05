#include "Form.h"

Form::Form(): _reqExecuteGrade(1), _reqSignGrade(1), _name(""){}

Form::Form(std::string name, const int reqSignGrade, const int reqExecuteGrade) \
: _reqExecuteGrade(reqExecuteGrade), _reqSignGrade(reqSignGrade), _name(name){}

Form::~Form() {}

Form::Form(const Form& other): _name(other.getName()), _reqExecuteGrade(other.getReqExecuteGrade()), _reqSignGrade(other.getReqSignGrade()) {
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
const int Form::getReqSignGrade() const {
    return this->_reqSignGrade;
}
const int Form::getReqExecuteGrade() const {
    return this->_reqExecuteGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {}
// void Form::signForm(void) {
//     if(this->getSigned())
//         std::cout << <bureaucrat> signed <form>
// }


std::ostream& operator<<(std::ostream &os, const Form& obj) {
    os << "form :" <<  obj.getName() << "with a " << obj.getReqExecuteGrade() \
    << "Required Execute Grade" << " and a " << obj.getReqSignGrade() \
    <<  "Required Sign Grade" \
    <<(obj.getSigned() ? "has been signed" : "has not been signed") \
    << std::endl;
    return os;
}
