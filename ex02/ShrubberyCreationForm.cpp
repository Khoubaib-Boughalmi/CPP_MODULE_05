#include "AForm.h"

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
    private :   
        const std::string   _target;
        typedef enum s_grade{
            SignGrade = 145,
            ExecuteGrade = 137
        } t_grade;
};