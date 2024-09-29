
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <vector>
#include <string.h>
#include <fstream>
using namespace std;

bool opcheck(string enteredOp) {
    if (enteredOp == "\+" || enteredOp == "\-" || enteredOp == "\*" || enteredOp == "\/") {
        return true;
    }
    else {
        return false;
    }
}

double dothemath(double num1, string op, double num2) {
    if (op == "\+") {
        return num1 + num2;
    }
    else if (op == "\-") {
        return num1 - num2;
    }
    else if (op == "\*") {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

int writetomyfile(vector<string> wholeexpression) {
    ofstream MyFile("calchistory.txt");
    for (int i = 0; i < wholeexpression.size(); i++) {
        MyFile << wholeexpression[i] << "\n";
    }
    MyFile.close();
    return 0;
}

int main()
{
    string keepgoing;
    string input1;
    string input2;
    string input3;
    double x;
    string operate;
    double y;
    double answertomath;
    vector<string> allInputs;
    bool checkop = false;
    

    cout << "Type 'end' at any time to exit.\n\n";
    while (true) {
        cout << "Enter first number: ";
        cin >> input1;

        if (input1 == "end") {
            return 0;
        }

        try {
            x = stoi(input1);
            allInputs.push_back(input1);
            break;
        }
        catch (const std::invalid_argument& e) {
            cout << "Invalid input. Please enter a number or 'end'" << endl;
        }
    }

    while (keepgoing != "end") {

        while (checkop != true) {
            cout << "Enter operator (\+, \-, \*, or \/): ";
            cin >> operate;
            if (operate == "end") {
                
                keepgoing = "end";
                return 0;
            }
            checkop = opcheck(operate);
            if (checkop == true) {
                allInputs.push_back(operate);
            }
        }

        while (true) {
            cout << "Enter another number: ";
            cin >> input2;

            if (input2 == "end") {
                
                keepgoing = "end";
                return 0;
            }

            try {
                y = stoi(input2);
                allInputs.push_back(input2);
                break;
            }
            catch (const std::invalid_argument& e) {
                cout << "Invalid input, please enter a number." << endl;
            }
        }

        answertomath = dothemath(x, operate, y);
        allInputs.push_back("=");
        allInputs.push_back(to_string(answertomath));
        allInputs.push_back("\n");
        cout << "Answer is: " << answertomath << "\n\n";

        cout << "Would you like to keep going (y or n)? ";
        cin >> input3;
        if (input3 == "y" || input3 == "Y" || input3 == "yes" || input3 == "YES") {
            x = answertomath;
            checkop = false;
        }
        else {
            writetomyfile(allInputs);
            keepgoing = "end";
            return 0;
        }
        
    }
}




