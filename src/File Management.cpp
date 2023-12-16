#include "Include.h"  //include the required modules

// Program to manage (create, append data, erase data, del) files

int FMmenu(std::vector<std::string> &options)
{
    std::cout << "---Menu---\n";
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << i << ": " << options[i] << "\n";
    }
    std::string input;
    int selection = -1;
    while (selection < 0 || selection > options.size() - 1)
    {
        try
        {
            std::cout << "Enter Selection: ";
            std::getline(std::cin, input);
            selection = std::stoi(input);
        }
        catch (std::invalid_argument const &e)
        {
            std::cout << "Selection must be between " << 0 << " and " << options.size() - 1 << "\n";
            continue;
        }
    }
    return selection;
}


int FMmain()
{
    std::vector<std::string> menuOptions {"Create File", "Delete File"};
    int selection = FMmenu(menuOptions);
    std::cout << "\nYou chose: " << selection << ", " << menuOptions[selection] << "\n";
    if (selection == 0)
    {
        std::string nfileName;
        std::cout << "Enter a new file name: ";
        std::getline(std::cin, nfileName);
        std::ofstream newFile(nfileName + ".txt");
        newFile << "This is the default text, entered upon file creation!";
        newFile.close();
        std::cout << "\nFile has been created with default text!";
    }
}