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
    
    //User interface that takes an input from the user
    string expression;
    cout << "--------348_Calculator_Project---------\n" << endl;
    cout << "Please enter your mathematical expression or TYPE 0 to EXIT" << endl;

    cin >> expression;

    if (expression == "0")
    {
        //end program
        return 0;
    }
    else
    {
        //Take given User expression and put it into our calc class
        Calculator calc(expression);
        double result = calc.calculate();

        //Return the result to the user ending main 
        cout << "Result = " << result << endl;

    }


   
    

    
}//end Main

