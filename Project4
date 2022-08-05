
//Author = Jordan Lyle
//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include "stack.h"


int main()
{
    Stack s;

    string placeholder;
    cout << "Enter filename: ";
    string filename = "";
    cin >> filename; // Takes the name of the file to be read.
    
    ifstream din;
    ofstream dout;
    din.open(filename.c_str());
    string outputName = "Example";
    outputName.push_back(filename[7]);
    outputName = outputName + "_Output.js";
    dout.open(outputName);
    if (din.fail() || dout.fail()) // Decides to continue commands only if the file can be opened.
    {
        cout << "Error: could not open file" << endl;
        return 1;
    }
    else
    {
        int spaceCount = -1;
        bool InQuote = false;
        while (!din.eof()) // Repeats until the file is done.
        {
            getline(din, placeholder); // Reads in line to the string.
            placeholder = placeholder.erase(0, placeholder.find_first_not_of(" ")); //Removes extra spaces in front of the string.
            placeholder = placeholder.erase(placeholder.find_last_not_of(" ") + 1); //Removes extra spaces at the end of the string.
            for (int unsigned i = 0; i < placeholder.size(); i++) //While the end of the string has not been reached.
            {
                if (placeholder[i] == '"' && InQuote == false) //If opening quote.
                {
                    s.Push("\""); //Add quote to stack.
                    InQuote = true; //Inside quote is now true.
                }
                else if (placeholder[i] == '"' && InQuote == true) //If closing quote.
                {
                    if (s.Top() == "\"") //If an opening quote is at the top of the stack.
                    {
                        s.Pop(); // Remove quote from stack.
                        InQuote = false; //No longer in quote.
                    }
                    else
                    {
                        return 0; // Will likely never run because it will check the entire statement to find closing quote before it returns ending error instead.
                    }
                }
                if (placeholder[i] == '{' && InQuote == false) //If open bracket and not in quotes.
                {
                    dout << endl;
                    spaceCount++; //Add extra spaces for formatting.
                    s.Push("{"); // Push open bracket to stack.
                    for (int j = 0; j < (spaceCount); j++) // Output extra spaces.
                    {
                        dout << "  ";
                    }
                    dout << placeholder[i]; // Output open bracket.
                    if (placeholder[i + 1] == ',') //If comma directly after then attach it to bracket.
                    {
                        i = i + 1;
                        dout << placeholder[i];
                    }
                    dout << endl;
                    for (int j = 0; j <= spaceCount; j++) //Add extra spaces to next output.
                    {
                        dout << "  ";
                    }
                }
                else if (placeholder[i] == '[' && InQuote == false) //If open bracket and not in quotes.
                {
                    dout << endl;
                        spaceCount++; //Add extra spaces for formatting.
                        s.Push("["); // Push open bracket to stack.
                        for (int j = 0; j < (spaceCount); j++) // Output extra spaces.
                        {
                            dout << "  ";
                        }
                        dout << placeholder[i]; // Output open bracket.
                        if (placeholder[i + 1] == ',') //If comma directly after then attach it to bracket.
                        {
                            i = i + 1;
                            dout << placeholder[i];
                        }
                        dout << endl;
                        for (int j = 0; j <= spaceCount; j++) //Add extra spaces to next output.
                        {
                            dout << "  ";
                        }
                }
                else if ((placeholder[i] == '}') && InQuote == false) //If closed bracket and not in quotes.
                { 
                    dout << endl;
                    if (s.Top() == "{") // If top of stack open bracket.
                    { 
                        s.Pop(); //Take it off stack.
                        for (int j = 0; j < (spaceCount); j++) // Add extra spaces.
                        {
                            dout << "  ";
                        }
                        dout << placeholder[i]; // Output closed bracket.
                        if (placeholder[i + 1] == ',') //If next output is comma attach it to bracket.
                        {
                            i = i + 1;
                            dout << placeholder[i];
                        }
                        dout << endl;
                        spaceCount--; //Subtract amount of spaces needed for indentation.
                        for (int j = 0; j <= spaceCount; j++) //Add extra spaces in front of next character.
                        {
                            dout << "  ";
                        }
                    }
                    else
                    {
                        cout << endl << "This input has errors, see them on the output file.";
                        dout << endl << "__________________________________" << endl << "ERROR, MISSING '{'"; //If no open bracket on top of stack, stop and send error.
                        return 0;
                    }

                }
                else if((placeholder[i] == ']') && InQuote == false) //If closed bracket and not in quotes.
                {
                    dout << endl;
                    if (s.Top() == "[") // If top of stack open bracket.
                    {
                        s.Pop(); //Take it off stack.
                        for (int j = 0; j < (spaceCount); j++) // Add extra spaces.
                        {
                            dout << "  ";
                        }
                        dout << placeholder[i]; // Output closed bracket.
                        if (placeholder[i + 1] == ',') //If next output is comma attach it to bracket.
                        {
                            i = i + 1;
                            dout << placeholder[i];
                        }
                        dout << endl;
                        spaceCount--; //Subtract amount of spaces needed for indentation.
                        for (int j = 0; j <= spaceCount; j++) //Add extra spaces in front of next character.
                        {
                            dout << "  ";
                        }
                    }
                    else
                    {
                        cout << endl << "This input has errors, see them on the output file.";
                        dout << endl << "__________________________________" << endl << "ERROR, MISSING '['"; //If no open bracket on top of stack, stop and send error.
                        return 0;
                    }
                }
                else if (placeholder[i] == ',') //If a character is a comma but not after a bracket of some sort.
                {
                    dout << placeholder[i]; //Output comma.
                    dout << endl; // Go to the next line.
                    for (int j = 0; j <= spaceCount; j++) //Output proper spaces in front of next character.
                    {
                        dout << "  ";
                    }
                }
                else
                {
                    dout << placeholder[i]; //If everything else is false, then it is normal character, and output normally.
                }
            }
        }
    }
    if (s.IsEmpty() != true) // If the stack is not empty.
    {
        cout << endl << "This input has errors, see them on the output file.";
        dout << endl << "_______________________";
        dout << endl << "ERROR, MISSING THE CLOSINGS FOR THESE OPERATORS: "; // Output error message.
        while (s.IsEmpty() != true) // while there are still items in stack.
        {
            dout << s.Top() << " "; // Output items still in stack.
            s.Pop(); //Remove them from stack.
        }
        return 0;
    }
    cout << endl << "The formatted code has been printed! There are no errors!";
}
