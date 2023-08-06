#include "Bureaucrat.h"

int main()
{
    try
    {
        Bureaucrat("Jhon Doe", 0);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return (0);
}