#include "RobotomyRequestForm.h"


RobotomyRequestForm::RobotomyRequestForm(): \
AForm("Default", this->SignGrade, this->ExecuteGrade), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): \
AForm(target, this->SignGrade, this->ExecuteGrade), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): \
AForm(other.getTarget(), other.SignGrade, other.ExecuteGrade),_target(other._target){}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void) other;
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const{
    return this->_target;   
}

void RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const {
    std::cout << "Making Some Drilling Noises" << std::endl;
    try
    {
        static bool is_seeded = false;
        if (!is_seeded) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            is_seeded = true;
        }
        check_permissions(bureaucrat);
        if(rand() % 2)
            std::cout <<  this->getTarget() << " Has Been Robotomized Successfully" << std::endl;
        else
            std::cout << "Robotomy Failed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
