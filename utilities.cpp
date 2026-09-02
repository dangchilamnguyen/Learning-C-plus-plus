#include "utilities.h"

#include <iostream>

using std::cin;
using std::cout;
using std::getline;
using std::stoi;

string read_string(string prompt)
{
    string result;

    cout << prompt;
    getline(cin, result);

    return result;
}

int read_integer(string prompt)
{
    string input;

    cout << prompt;
    getline(cin, input);

    return stoi(input);
}