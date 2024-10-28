#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char opening, char closing) 
{
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

string checkBrackets(const string& input) 
{
    stack<char> bracketStack; 
    string errorPosition; 

    for (size_t i = 0; i < input.length(); ++i) 
    {
        char current = input[i];

        if (current == '(' || current == '{' || current == '[') 
        {
            bracketStack.push(current);
        }
        else if (current == ')' || current == '}' || current == ']') 
        {
            if (bracketStack.empty()) 
            {
                errorPosition = "Error, no bracket for '" + string(1, current) + "' in place " + to_string(i + 1);
                return errorPosition;
            }

            char top = bracketStack.top();
            bracketStack.pop();

            if (!isMatchingPair(top, current)) 
            {
                errorPosition = "Error, no bracket for '" + string(1, top) + "' è '" + string(1, current) + "' in place " + to_string(i + 1);
                return errorPosition;
            }
        }
        else if (current == ';') 
        {
            break;
        }
    }

    if (!bracketStack.empty()) 
    {
        errorPosition = "Error, no bracket for '" + string(1, bracketStack.top()) + "'";
        return errorPosition;
    }

    return "Correct";
}

int main() 
{
    string input;
    cout << "Input text with (finish ';'): ";
    getline(cin, input);

    if (!input.empty() && input.back() == ';') 
    {
        input.pop_back();
    }

    string result = checkBrackets(input);
    cout << result << endl;
}