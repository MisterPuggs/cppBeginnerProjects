#include "Include.h"  //include the required modules

void ACGetDigitValue(std::vector<int> &values) {
    // User increases ints in vector parameter
    std::string input;
    std::cout << "Provide new digit :";
    std::getline(std::cin, input); std::cin;
    if (input == "END" || input == "end") values.push_back(-1);
    for (char a : input){
        if (std::isdigit(a)) values.push_back(a-48);
    }
}

void ACGetNumericValue(std::vector<int> &values) {
    std::string input;
    bool isInt;
    std::cout << "Provide new digit :";
    std::getline(std::cin, input); std::cin;
    if (input == "END" || input == "end") values.push_back(-1);
    // Check is int:
    for (char c : input){
        if (!std::isdigit(c)){ isInt = false; }
    }
    int newInt = std::stoi(input);
    if (!isInt) values.push_back(newInt);
}

int ACmain() {
    // A basic comment example
    std::cout << "C++ Program 1 \n";
    std::vector<int> values;
    std::vector<int> numValues;
    std::string option = "digit";
    std::cout << "Enter [digit] for single digit entry, else enter [Numeric] for numeric entry.\n";

    std::getline(std::cin, option);
    if (option == "digit") {
        for (int i = 0; i < 10; i++){
            ACGetDigitValue(values);
            std::cout << values.back() << "\n Current list of values: ";
            if (values.back() == -1) {
                values.pop_back();
                break;
            }
        }
        if (values.back() == -1) values.pop_back();
    }
    else {
        for (int j = 0; j < 10; j++){
            ACGetNumericValue(numValues);
            std::cout << numValues.back() << "\n Current list of values: ";
            for (int x : numValues)
                std::cout << x << "\n";
            if (numValues.back() == -1)
            {
                std::cout << "ending loop \n";
                numValues.pop_back();
                break;
            }
        }
        if (numValues.back() == -1) numValues.pop_back();
    }

    std::cout << "Value Obtain Loop ended. \n Final Values: ";
    for (int val : values) std::cout << val << " ";
    std::cout << "\n";

    // Produce Averages:
    if (values.empty())
    {
        // Averages from single digit values
        int sum = std::accumulate(values.begin(), values.end(), 0);
        float mean = float(sum) / values.size();
        std::cout << mean << " is the mean.\n";
        std::cout << (values.size());


    } else
    {

    }


    // Averages from multiple digit values

}