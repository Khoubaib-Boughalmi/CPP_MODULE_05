#include "ShrubberyCreationForm.h"


ShrubberyCreationForm::ShrubberyCreationForm(): \
AForm("Default", this->SignGrade, this->ExecuteGrade), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): \
AForm(target, this->SignGrade, this->ExecuteGrade), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): \
AForm(other.getTarget(), other.SignGrade, other.ExecuteGrade),_target(other._target){}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->_target;   
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::string _tree = "          _-_          "
                        "        /~~   ~~\      "
                        "    /~~         ~~\    "
                        "    {               }  "
                        "    \  _-     -_  /    "
                        "    ~  \\ //  ~        "
                        "    _- -   | | _- _    "
                        "    _ -  | |   -_      "
                        "        // \\          ";

    std::string _fName = this->_target + "_shrubbery";
    std::ofstream outFile(_fName, std::ios::out);
    if(!outFile)
        throw OpenFileException();
    outFile << _tree;
    std::cout << "Shrubbery Created Successfully" << std::endl;
}
