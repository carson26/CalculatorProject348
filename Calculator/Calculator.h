/*
* Names Here:
* Calculator348 Project
* Calculator.h
*/

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
using namespace std;


//quick note on how to read documentation! (just in case I am doing it weird and you guys learned a better way to do it)
/**
* The first line is meant to explain the purpose of a function
* @param parameterName These are supposed to tell you what the function expects as
* a parameter. There can be multiple!
* @return This is what the function is supposed to return.
* @pre This are things that must be true for the function to work properly, there
* can be multiple of these also.
*/


//These functions are based on what we talked about previously so feel free
// to change it up if you find a better way to implement any of this!


class Calculator
{
private:
	string expression;

	/**
	* Converts a given character into a double
	* @param n The character that is to be converted.
	* @return Double equivalent of the converted character
	* @pre The given character must be a number.
	*/
	double convertHelper(char n);

	/**
	* Calculates the precendence of the given operator.
	* @param op The given operator.
	* @return The assigned number of precedence as an integer.
	* @pre The character passed into this method must be an operator.
	*/
	int precedenceHelper(char op);

	/**
	* Converts a stored user submitted expression into a postfix expresstion with the 
	* use of a stack.
	* @return The calculated postfix expresssion
	* @pre All sumbmitted expresssions are written properly
	* @pre No decimal numbers are used
	*/
	string precedence();

	/**
	* Adds the two given numbers together
	* @param a A number to be added
	* @param b A number to be added
	* @return The sum of the two numbers
	*/
	double add(char a, char b);

	/**
	* Subtracts the two given numbers
	* @param a The number to be subtracted from
	* @param b The number to be subtracted
	* @return The difference of the two numbers
	*/
	double subtract(char a, char b);

	/**
	* Divides the two given numbers from eachother
	* @param a The number to be divided.
	* @param b The number used to divide
	* @return The quotient of the two numbers
	*/
	double divide(char a, char b);

	/**
	* Multiplies the two given numbers together
	* @param a A number to be multiplied
	* @param b A number to be multiplied
	* @return The product of the two numbers
	*/
	double multiply(char a, char b);

	/**
	* Produces the remainder for the two given numbers
	* @param a A number to be divided
	* @param b A number to be used to divide
	* @return The remainder of the division between the two numbers
	* @pre The remainder of two numbers will always be an whole number
	*/
	double modulus(char a, char b);


public:

	Calculator(); //default constructor

	Calculator(string expresssion); //constructor

	void set(string a); // sets expression

	string get(); //gets expression

	/**
	* Converts the stored expression to a postfix expression and then evaluates it 
	* using a stack.
	* @return The evaluated resul of the postfix expression.
	*/
	double calculate();



};//end class Calculator



#endif
