/**
* Names here:
*  Calculator348 Project
* Calculator.cpp
*/

#include "Calculator.h"
#include <string>
#include <stack> // library with stack class
#include <stdexcept> //library for error handling
#include <algorithm> //library with a bunch of simple algorthims, might come in handy 

/**
* Quick basic stack notes: (We should put some here so we dont end up opening 10 different tabs for the same info)
* 
*/


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

double Calculator::convertHelper(char n)
{

}//end convertHelper

string Calculator::precedence()
{
	
}//end precedence

double Calculator::add( char a, char b)
{

}//end add

double Calculator::subtract(char a, char b)
{

}//end subtract

double Calculator::divide(char a, char b)
{

}//end divide

double Calculator::multiply(char a, char b)
{

}//end multiply

double Calculator::modulus(char a, char b)
{

}//end modulus

double Calculator::calculate()
{

}//end calculate




