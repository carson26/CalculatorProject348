/**
* Names here: Carson Abbott, Owen Deines, Brisa Andrade, Jordan Mcdaniels, Jaret Priddy, Connor Schroeder
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
            try {
                // Try to calculate the expression
                double result = calc.calculate();
                // Return the result to the user if no errors were thrown
                cout << "Result = " << result << endl;
            }
            catch (int errorCode) {
                // If an error is thrown (ie. 'throw 100;'), 100 will be caught as the error code
                cout << "Error Code: " << errorCode << endl;
                // Put any more possible errorCodes inside this switch case statement
                switch (errorCode) {
                    case 100:
                        cout << "\tZero Division Error" << endl;
                        break;
                }
            }
        }
    }
    return 0; // End the program
}
