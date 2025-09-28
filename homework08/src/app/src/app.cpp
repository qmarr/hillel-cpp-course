#include "app/app.h"

app::app()
{
    std::cout << "default constructor created";
}


app::app(std::string name) : appName(name)
{
        std::cout << "std::string constructor created";
}

app::~app()
{
        std::cout << "default destructor called";
}

void app::printApp()
{
#ifndef USEANOTHERLIB
    std::cout << "\nHELLO, I'M AN DEFAULT APP!XD\n" << std::endl;
#else
    std::cout << "\nHELLO, I'M AN ALTERNATIVE APP!XD\n" << std::endl;
#endif
}