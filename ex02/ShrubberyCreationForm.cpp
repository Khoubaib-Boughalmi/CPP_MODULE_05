#include "ShrubberyCreationForm.h"


ShrubberyCreationForm::ShrubberyCreationForm(): \
AForm("Default", this->SignGrade, this->ExecuteGrade), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): \
AForm(target, this->SignGrade, this->ExecuteGrade), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): \
AForm(other.getTarget(), other.SignGrade, other.ExecuteGrade),_target(other._target){}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void) other;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->_target;   
}

int ShrubberyCreationForm::check_permissions(const Bureaucrat& bureaucrat) const{
    if(bureaucrat.getGrade() <= this->getReqSignGrade())
        return (1);
    else
        throw GradeTooLowException();
}


// "          _-_           __________________                           _-_           "
// "        /~~   ~~\\      < srsly dude, why? >                      /~~   ~~\\       "
// "    /~~         ~~\\     ------------------                    /~~         ~~\\    "
// "    {               }          \\      ^__^                    {               }   "
// "    \\  _-     -_  /             \\   (oo)\\_______           \\  _-     -_  /     "
// "   \\  ~  \\ //  ~                    (__)\\       )\\/        \\  ~ \\ //  ~      "
// "    _- -   | | _- _                        ||----w |          _- -   | | _- _      "
// "      _ -  | |   -_                        ||     ||            _ -  | |   -_      "
// "          // \\                                                     // \\          "

void ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const {
    (void) bureaucrat;
    std::string _tree ="          _-_           __________________                           _-_          \n"
                       "        /~~   ~~\\      < srsly dude, why? >                      /~~   ~~\\      \n"
                       "    /~~         ~~\\     ------------------                    /~~         ~~\\   \n"
                       "    {               }          \\      ^__^                    {               }  \n"
                       "    \\  _-     -_  /             \\   (oo)\\_______           \\  _-     -_  /    \n"
                       "   \\  ~  \\ //  ~                    (__)\\       )\\/        \\  ~ \\ //  ~     \n"
                       "    _- -   | | _- _                        ||----w |          _- -   | | _- _     \n"
                       "      _ -  | |   -_                        ||     ||            _ -  | |   -_     \n"
                       "          // \\                                                     // \\         \n";


    try
    {
        this->check_permissions(bureaucrat);
        std::string _fName = this->_target + "_shrubbery";
        std::ofstream outFile(_fName.c_str(), std::ios::out);
        if(!outFile)
            throw OpenFileException();
        outFile << _tree;
        std::cout << "Shrubbery Created Successfully" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
