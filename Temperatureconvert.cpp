#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int choice;
    double temp;

    std::cout << "*** Temperature converter ***\n";
    std::cout << "1. C to F \n";
    std::cout << "2. F to C \n";
    std::cout << "Choose your converter (1/2): ";
    std::cin >> choice;
    std::cout << "Enter temp: ";
    std::cin >> temp;
    if (choice == 1)
    {
        temp = (temp * 9.0 / 5.0) + 32;
        std::cout << temp;
    }
    else if (choice == 2)
    {
        temp = (temp - 32) * 5.0 / 9.0;
        std::cout << temp;
    }

    else
    {
        std::cout << "Invalid";
    }
    system("pause");
    return 0;
}