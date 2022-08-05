//-----------------------------------------------------------
//  Purpose:    Implementation of integer Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
    for (int index = 0; index < MAX_SIZE; index++)
        data[index] = ' ';
    top = -1;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
Stack::Stack(const Stack& stack)
{
    for (int index = 0; index < MAX_SIZE; index++)
        data[index] = stack.data[index];
    top = stack.top;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(string word)
{
    // Check for full stack
    if (IsFull())
        return;

    // Save data in stack
    data[++top] = word;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
string Stack::Pop()
{
    // Check for empty stack
    if (IsEmpty())
        return "Empty";

    // Remove top value from stack
    return (data[top--]);
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
string Stack::Top()
{
    // Check for empty stack
    if (IsEmpty())
        return "Empty";

    // Return top value from stack
    return (data[top]);
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull()
{
    return (top == MAX_SIZE - 1);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
    return (top == -1);
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
    cout << "stack: ";
    for (int index = 0; index <= top; index++)
        cout << data[index];
    cout << endl;
}
