#include "AForm.h"

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private :   
        const std::string   _target;
        int const SignGrade = 145;
        int const ExecuteGrade = 13;
};