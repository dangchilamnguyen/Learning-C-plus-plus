#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib> // rand() srand()

int main()
{
    srand(time(NULL));
    int ans = (rand() % 100) + 1;
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;
    while (number != ans)
    {

        if (number > ans)
        {
            std::cout << "The answer is smaller\n";
        }
        else if (number < ans)
        {
            std::cout << "The answer is bigger\n";
        }
        std::cout << "Enter a number: ";
        std::cin >> number;
    }

    std::cout << "The answer is correct";

    return 0;
}