#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib> // rand() srand()

int main()
{
    srand(time(NULL));
    int num = (rand() % 6) + 1; // number six -> 6 numbers 0->5
    // number 100 -> 100 numbers 0->99
    std::cout << num;
    return 0;
}