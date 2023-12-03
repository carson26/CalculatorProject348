/**
* Names here:
*  Calculator348 Project
* Calculator.cpp
*/

#include "Calculator.h"
#include <iostream>
#include <string>
#include <stack> // library with stack class
#include <stdexcept> //library for error handling
#include <algorithm> //library with a bunch of simple algorthims, might come in handy idk
#include <cmath>


using namespace std;

Calculator::Calculator() : expression("")
{

}// end default constructor

Calculator::Calculator(string exp)
{
	expression = exp;
}//end constructor

void Calculator:: set(string newExp)
{
	expression = newExp;
}//end set

string Calculator::get()
{
	return expression;
}//end get

void Calculator::removeSpaces()
{
	string exp = get();
	int length = exp.length();
	int spaceCount = 0;

	//Calculates the number of white spaces in the given expression

	spaceCount = count(exp.begin(), exp.end(),' ');

	if (spaceCount > 0)
	{
		//Removes the spaces in the expression
		exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());
		set(exp);
	}
}//end removeSpaces

double Calculator::convertHelper(char n)
{
	double num;

	//Turns the given character into string in order to use stod()
	string temp = "";
	temp += n;
	
	//stod() converts string into a double
	num = stod(temp);
	return num;


}//end convertHelper

int Calculator::precedenceHelper(char op)
{
	int preValue = 0;

	//Determines the precendence of a given operator
	if (op == '+' || op == '-')
	{
		preValue = 1;
	}
	else if (op == '*' || op == '/' || op == '%')
	{
		preValue = 2;
	}
	else if (op == '^')
	{
		preValue = 3;
	}

	return preValue;

}//end precedenceHelper

bool Calculator::comparePrecendence(char op1, char op2)
{
	bool precendence = false;

	int a = precedenceHelper(op1);
	int b = precedenceHelper(op2);

	//Compares the precendence value of given operators

	if (a <= b)
	{
		precendence = true;
	}
	
	return precendence;

}//end comparePrecendence 


char Calculator::sortType(char ch) 
{
	char type = ' ';

	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ||
		ch == '6' || ch == '7' || ch == '8' || ch == '9')
	{
		// Sets type to n if character is a number
		type = 'n';
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
	{
		//Sets type to o if the character is an operator
		type = 'o';
	}
	else if (ch == '(' || ch == ')')
	{
		//returns character unchanged of the character is a paranthesis
		type = ch;
	}

	return type;

}//end sortType

string Calculator::precedence()
{
    string postFixExp = "";
    removeSpaces();

    string exp = get();

    int expLength = exp.length();
    char ch = ' ';

    stack<char> aStack;

    for (int i = 0; i < expLength; i++)
    {
        ch = exp[i]; //I dont know what this does come back to this -------------------------------------------------------------------------

        switch (sortType(ch))
        {
        case 'n':
        {
            //Appends number to postFixExp
            postFixExp += ch;
            break;
        }
        case '(':
        {
            aStack.push(ch);
            break;
        }
        case 'o':
        {
            while (!aStack.empty() && aStack.top() != '(' &&
                   comparePrecendence(ch, aStack.top()))
            {
                //Append top of stack to PostFixExp
                postFixExp += (aStack.top());
                aStack.pop();
            } //end while

            aStack.push(ch);
            break;
        }
        case ')':
            while (aStack.top() != '(')
            {
                postFixExp += aStack.top();
                aStack.pop(); //--------------------------------------------------------------------------------------
            }

            aStack.pop();
            break;
        } //end switch
    }     // end for

    while (!aStack.empty())
    {
        postFixExp += (aStack.top());
        aStack.pop();
    }
    
    return postFixExp;
} //end precedence


double Calculator::add( double a, double b)
{
	return a + b;
}//end add

double Calculator::subtract(double a, double b)
{
	return a - b;
}//end subtract

double Calculator::divide(double a, double b)
{
    double result = 0.0;
    if (b == 0)
    {
        throw runtime_error("There was an attempt to divide by 0.");
    }
    else
    {
        result = a / b;
    }
    return result;
}

double Calculator::multiply(double a, double b)
{
	return a * b;
}//end multiply

double Calculator::modulus(double a, double b)
{
	//convert doubles into integers
	int op1 = (int)a;
	int op2 = (int)b;


	return op1 % op2;
}//end modulus

double Calculator::exponent(double a, double b)
{
	return pow(a, b);

}//end exponent

double Calculator::calculate()
{
	double result = 0;
	string exp = precedence();
	int expLength = exp.length();

	stack <double> evalStack;

	char ch = ' ';

	for (int i = 0; i < expLength; i++)
	{
		ch = exp[i];

		if (sortType(ch) == 'n')
		{
			double num = convertHelper(ch);
			evalStack.push(num);
		}
		else
		{
			double op2 = evalStack.top();
			evalStack.pop();

			// If stack is not empty, retrieve op1
			if (!evalStack.empty()) {
				double op1 = evalStack.top();
				evalStack.pop();

				switch (ch)
				{
				case '+':
					result = add(op1, op2);
					break;
				case '-':
					result = subtract(op1, op2);
					break;
				case '*':
					result = multiply(op1, op2);
					break;
				case '/':
					result = divide(op1, op2);
					break;
				case '%':
					result = modulus(op1, op2);
					break;
				case '^':
					result = exponent(op1, op2);
					break;
				}//end switch

				// Place result on stack
				evalStack.push(result);
			}
			else
			{
				// Handle the case where there are not enough operators on the stack
				cout << "Error: Insufficient operators for calculation." << endl;
				// You may choose to throw an exception or handle this error appropriately
				// For now, the result remains 0
				return result;
				//evalStack.push(0);  // Placeholder value, adjust as needed
			}
		}
	}

	return result;
}//end calculate
