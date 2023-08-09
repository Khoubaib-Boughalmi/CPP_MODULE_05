#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private :
        const std::string   _target;
        typedef enum s_req {
            SignGrade = 25,
            ExecuteGrade = 5
        } t_req;
};
