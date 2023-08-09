#include "AForm.h"

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private :   
        const std::string   _target;
        typedef enum s_req {
            SignGrade = 72,
            ExecuteGrade = 45
        } t_req;
};