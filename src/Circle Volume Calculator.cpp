#include "Include.h"  //include the required modules

// Program to calculate area of circle, sphere and volume.

float CVCEnsureFloatInput(std::string const& prompt, float defReturn = 0.0)
{
    std::string strInput; float input;
    try
    {
        std::cout << prompt;
        std::getline(std::cin, strInput);
        input = std::stof(strInput);
        return input;
    }
    catch (std::invalid_argument const &e)
    {
        return defReturn;
    }
}

int CVCmenu()
{
    std::string const options[] = {"Circle Area", "Sphere Volume", "Cylinder Volume"};
    std::string selection;
    float input = -1.0;
    do
    {
        std::cout << "Please select an option from:\n";
        for (int o = 0; o < sizeof(options)/sizeof(options[0]); o++)
        {
            std::cout << o << ": Calculate " << options[o] << "\n";
        }
        input = CVCEnsureFloatInput("", -1.0);
    } while (input < 0 || sizeof(options)/sizeof(options[0])-1 < input);
    return int(input);
}


int CVCmain(int iter = 0)
{
    float radius, height, area, volume;
    int calcSelection = CVCmenu();
    radius = CVCEnsureFloatInput("Enter radius: ");
    if (calcSelection == 0)
    {
        area = M_PI * std::pow(radius, 2);
        std::cout << "Area of the circle is: " << area << "\n";
    }
    if (calcSelection == 1)
    {
        volume = 4.0 / 3 * M_PI * std::pow(radius, 3);
        std::cout << "Volume of the sphere is " << volume << "\n";
    }
    if (calcSelection == 2)
    {
        area = M_PI * std::pow(radius, 2);
        height = CVCEnsureFloatInput("Enter cylinder height: ");
        volume = area * height;
        std::cout << "Volume of the cylinder is " << volume << "\n";
    }
    std::cout << "\n\n\n";
    if (iter < 10) CVCmain(iter + 1);
    return 0;
}