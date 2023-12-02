/**
* Names here:
* Calculator348 Project
* main.cpp
*/


#include "Calculator.cpp"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    // Here is where the user interface will be implemented for the most part!

    string expression;
    cout << "--------Calculator---------\n" << endl;
    cout << "Please Enter a mathematical expression or TYPE 0 to EXIT" << endl;

    cin >> expression;

    if (expression == "0")
    {
        //end program
    }
    else
    {
        Calculator calc(expression);
        double result = calc.calculate();

        cout << "Result:" << result << endl;

    }


   
    

    
}//end Main

