#include "Include.h"  //include the required modules
std::random_device rd;
std::mt19937 gen(rd());

class Character
{
    public:
        void SetName(std::string &nameString)
        {
            // split name:
            std::vector<std::string> nameSegList;
            int splitloc = int(nameString.find(' ')), frompos = 0;
            while (splitloc != -1) {
                nameSegList.push_back(nameString.substr(frompos, splitloc-frompos));
                frompos = splitloc + 1;
                splitloc = int(nameString.find(' ', frompos));
            }
            nameSegList.push_back(nameString.substr(frompos, splitloc));
            firstName = nameSegList.front();
            lastName = nameSegList.back();
            fullName = nameString;
        }
        explicit Character(std::string &nameString)
        {
            SetName(nameString);
        }

        void EarnMoney ()
        {
            std::uniform_real_distribution<> distribute(0.7, 1);
            earnHist.push_back(maxEarn * distribute(gen));
            bal += earnHist.back();
        }

        std::string GetFirstName() {return firstName;}
        std::string GetLastName() {return lastName;}
        std::string GetFullName() {return fullName;}
        double GetBal() {return bal;}
        std::vector<double> GetEarnHist() {return earnHist;};

    private:
        std::string firstName, lastName, fullName;
        double bal = 0, maxEarn = 500;
        std::vector<double> earnHist;
};

void CCmain()
{
    std::string nameInput;
    std::cout << "Please enter a name for a new character: \n";
    std::getline(std::cin, nameInput);
    Character newCharacter(nameInput);
    std::cout << "Name set to: " << newCharacter.GetFirstName() << " " << newCharacter.GetLastName() << "\n";
    std::cout << "Full name: " << newCharacter.GetFullName() << "\n";

    std::string selection;
    while (selection != "end" || selection != "END")
    {
        std::cout << "Enter selection [earn], [bal], [hist]: ";
        std::getline(std::cin, selection);
        std::cout << "\n";
        if (selection == "earn") newCharacter.EarnMoney();
        if (selection == "bal")
        {
            std::cout << newCharacter.GetFirstName() << "'s Balance is " << char(156);
            std::cout << double(newCharacter.GetBal()) << "\n";
        }
        if (selection == "hist")
        {
            std::vector<double> earnHist = newCharacter.GetEarnHist();
            std::cout << newCharacter.GetFirstName() << "'s Earnings history is: \n";
            for (double earn : earnHist)
            {
                std::cout << ", +" << char(156) << earn << " ";
            }
            std::cout << "\n";
        }

    }
}