#include "Bureaucrat.h"

class Bureaucrat;

class Form{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _reqSignGrade;
        const int           _reqExecuteGrade;
    public:
        Form();
        Form(std::string name, const int reqSignGrade, const int reqExecuteGrade);
        Form(const Form& other);
        const Form& operator=(const Form& other);
        ~Form();
        const std::string getName(void) const;
        bool getSigned(void) const;
        const int getReqSignGrade(void) const;
        const int getReqExecuteGrade(void) const;
        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &os, const Form& obj);

