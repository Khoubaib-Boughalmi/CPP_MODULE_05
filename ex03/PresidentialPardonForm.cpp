#include "PresidentialPardonForm.h"


PresidentialPardonForm::PresidentialPardonForm(): \
AForm("Default", this->SignGrade, this->ExecuteGrade), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): \
AForm(target, this->SignGrade, this->ExecuteGrade), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): \
AForm(other.getTarget(), other.SignGrade, other.ExecuteGrade),_target(other._target){}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void) other;
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const{
    return this->_target;   
}

void PresidentialPardonForm::execute(Bureaucrat const & bureaucrat) const {
        check_permissions(bureaucrat);
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
