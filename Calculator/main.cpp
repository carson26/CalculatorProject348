/**
* Names here:
* Calculator348 Project
* main.cpp
*/


#include "Calculator.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    while (true)
    {
        // User interface that takes an input from the user
        string expression;
        cout << "--------348_Calculator_Project---------\n" << endl;
        cout << "Please enter your mathematical expression or TYPE 0 to EXIT" << endl;

        // Use getline to read the entire line of input
        getline(cin, expression);

        if (expression == "0")
        {
            // End the program if the user inputs '0'
            break;
        }
        else
        {
            // Take the given user expression and put it into our calc class
            Calculator calc(expression);
            double result = calc.calculate();

            // Return the result to the user
            cout << "Result = " << result << endl;
        }
    }

    return 0; // End the program
}
