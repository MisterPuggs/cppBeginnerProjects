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

struct CurrentFile
{
    bool exists = false;
    std::string name;
    std::fstream file;
    void DetermineExists()
    {
        std::fstream f;
        f.open(name, std::ios::in);
        if (f){ f.close(); exists = true;}
        else{ f.close(); exists = false;}
    }
    void SetName()
    {
        std::string filename;
        std::cout << "Enter file name: ";
        std::getline(std::cin, filename);
        name = filename + ".txt";
        DetermineExists();
    }
};

// Def vars
std::vector<std::string> menuOptions {"Create File", "Delete File", "Empty File", "Write to File"};
CurrentFile f;
int selection;

int FMmain()
{
    //Mainloop
    selection = FMmenu(menuOptions);
    std::cout << "\n---You chose: " << selection << ", " << menuOptions[selection] << "---\n";
    if (selection == 0)
    {
        f.SetName();
        if (f.exists) std::cout << "CurrentFile already Exists!\n";
        else
        {
            f.file.open(f.name, std::ios::out);
            f.file << "This text has been created.";
            f.file << "\nDefault text has been inserted.";
            f.file.close();
            std::cout << "\nCurrentFile has been created with default text!";
        }
    }
    if (selection == 1)
    {
        f.SetName();
        if (f.exists)
        {
            std::remove((f.name).c_str());
            f.DetermineExists();
            std::cout << "\nCurrentFile has been removed!";
        }
        else std::cout << "\nCurrentFile does not exist!";
    }
    if (selection == 2)
    {
        f.SetName();
        if (f.exists)
        {
            f.file.open(f.name, std::ios::out);
            f.file.close();
            std::cout << "\nFile has been Wiped.";
        }
        else std::cout << "\nCurrentFile does not exist!";
    }
    if (selection == 3)
    {
        f.SetName();
        if (f.exists)
        {
            f.file.open(f.name, std::ios::app);
            std::cout << "\nFile opened for data appending. enter [END] on a new line to end input:\n";
            std::string lineInput;
            f.file << "\n";
            while (true)
            {
                std::getline(std::cin, lineInput);
                if (lineInput == "END" || lineInput == "end") break;
                f.file << lineInput << "\n";
                std::cout << lineInput;
            }
            f.file.close();
            std::cout << "Data entry ended.";
        }
        else std::cout << "\nCurrentFile does not exist!";
    }

    // Provide repeat break
    std::string contInput = "Y";
    std::cout << "Continue? [Y], [N]: ";
    std::getline(std::cin, contInput);
    std::cout << "\n\n\n";
    if (contInput == "Y" || contInput == "y") {FMmain();}
    return 0;
}