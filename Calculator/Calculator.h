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



class Calculator
{
private:
	string expression;

	/**
	* Removes potential white spaces to the given function and sets result as 
	* new expression.
	*/
	void removeSpaces();

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
	
	/*
	* Determines the precendence between two given operators.
	* @param a The first operator
	* @param b The second operator
	* #return true if the first operator is of equal or lesser precendence than
	* the second given operator, false if otherwise.
	*/
	bool comparePrecendence(char op1, char op2);

	/*
	*Calculates the character type of the given character.
	* @param ch The character whose type is being evaluated
	* @returns n if the character was an integer between 0-9.
	* @returns o if the character was a paranthesis
	* @pre The given characteres must meet the criteria of the above character
	* types
	*/
	char sortType(char ch);

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
	double add(double a, double b);

	/**
	* Subtracts the two given numbers
	* @param a The number to be subtracted from
	* @param b The number to be subtracted
	* @return The difference of the two numbers
	*/
	double subtract(double a, double b);

	/**
	* Divides the two given numbers from eachother
	* @param a The number to be divided.
	* @param b The number used to divide
	* @return The quotient of the two numbers
	*/
	double divide(double a, double b);

	/**
	* Multiplies the two given numbers together
	* @param a A number to be multiplied
	* @param b A number to be multiplied
	* @return The product of the two numbers
	*/
	double multiply(double a, double b);

	/**
	* Produces the remainder for the two given numbers
	* @param a A number to be divided
	* @param b A number to be used to divide
	* @return The remainder of the division between the two numbers
	* @pre The remainder of two numbers will always be an whole number
	*/
	double modulus(double a, double b);

	/**
	* Produces the exponent of a^b
	* @param a The base number 
	* @param b The power that the number will be raised by.
	* @return The product of the exponent
	*/
	double exponent(double a, double b);


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

