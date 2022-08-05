#ifndef STACK_H
#define STACK_H

//-----------------------------------------------------------
//  Purpose:    Header file for the character Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
const int MAX_SIZE = 100;

class Stack
{
public:
	// Constructors
	Stack();
	Stack(const Stack& stack);
	~Stack();

	// Methods
	void Push(string word);
	string Pop();
	string Top();

	// Other methods
	bool IsFull();
	bool IsEmpty();
	void Print();

private:
	string data[MAX_SIZE];
	int top;
};

#endif
