#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    double a;
    double b;
    char c;
    std::cout << "First number : ";
    std::cin >> a;

    std::cout << "Mathematical symbol: ";
    std::cin >> c;

    std::cout << "Second number: ";
    std::cin >> b;

    switch (c)
    {
    case '+':
        std::cout << a + b;
        break;
    case '-':
        std::cout << a - b;
        break;
    case '*':
        std::cout << a * b;
        break;
    case '/':
        if (b == 0)
        {
            std::cout << "Can't divide by 0!";
        }
        else
        {
            std::cout << a / b;
        }
        break;
    default:
        std::cout << "Invalid";
        break;
    }

    return 0;
}