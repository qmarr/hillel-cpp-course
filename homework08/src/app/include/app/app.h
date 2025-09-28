#include <string>
#include <iostream>

class app
{
private:
    std::string appName{"BlankApp"};
public:
    app();
    app(std::string name);
    ~app();
    void printApp();
};


